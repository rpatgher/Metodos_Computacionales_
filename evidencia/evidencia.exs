#
# Remy Patgher
# 2024-05-17

defmodule Lexer do

  def read_file(in_filename, out_filename) do
    {:ok, out_file} = File.open(out_filename, [:write])
    write_head(out_file)
    File.stream!(in_filename)
    |> Enum.map(&validate_line(&1, out_file, ""))

    write_foot(out_file)
    File.close(out_file)
  end

  def validate_line(line, file, new_line) do
    regexes = [
      {"comment", "//.*"},
      {"world", "World"},
      {"reserved", "if|else|while|do|for|return|break|continue"},
      {"operator", "[+\\-*/%]"},
      {"comparison", "==|!=|<=|>=|<|>"},
      {"assignment", "="},
      {"delimiter", "[;{},()]"},
      {"identifier", "[a-zA-Z_][a-zA-Z0-9_]*"},
      {"number", "[0-9]+"},
      {"string", "\"[^\"]*\""},
      {"char", "'.'"},
      # {"space", "[ ]+"},
    ]
    {str, new_line} = test_regex(line, regexes, file, new_line)
    if str != "" do
      validate_line(str, file, new_line)
    else
      write_line(file, new_line)
    end
  end

  def test_regex(str, [head | tail], file, new_line) do
    match = Regex.scan(~r/#{elem(head, 1)}/, str)
    if match != [] do
      [found_str | rest] = String.split(str, "#{Enum.at(match, 0)}", parts: 2)
      {Enum.join(rest), "#{new_line}#{found_str}#{to_html(elem(head, 0), Enum.at(match, 0))}"}
    else
      test_regex(str, tail, file, new_line)
    end
  end

  def test_regex(str, [], _file, new_line) do
    {"", "#{new_line}#{str}"}
  end

  def to_html(type, token) do
    "<span class=\"#{type}\">#{token}</span>"
  end

  def write_line(file, text) do
    fomated_text = String.replace(text, "\n", "")
    IO.puts(file, fomated_text)
  end

  def write_head(file) do
    File.stream!("head.html")
    |> Enum.map(&IO.puts(file, &1))
  end

  def write_foot(file) do
    File.stream!("foot.html")
    |> Enum.map(&IO.puts(file, &1))
  end

end


[in_file] = System.argv()
filename = Enum.at(String.split(in_file, "."), 0)
Lexer.read_file(in_file, "#{filename}.html")
