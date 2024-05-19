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
    keywords = [
                  "if",
                  "else",
                  "while",
                  "do",
                  "for",
                  "return",
                  "break",
                  "continue",
                  "int",
                  "float",
                  "char",
                  "string",
                  "void",
                  "struct",
                  "typedef",
                  "sizeof",
                  "enum",
                  "static",
                  "const",
                  "extern",
                  "register",
                  "auto",
                  "volatile",
                  "union",
                  "goto",
                  "case",
                  "default",
                  "switch",
                  "include",
                  "define",
                  "ifdef",
                  "ifndef",
                  "endif",
                  "elif",
                  "else",
                  "error",
                  "pragma",
                  "undef",
                  "line",
                  "warning",
                  "import",
                  "module",
                  "export",
                  "public",
                  "private",
                  "protected",
                  "class",
                  "interface",
                  "extends",
                  "implements",
                  "abstract",
                  "using",
                  "namespace",
                  "cin",
                  "cout",
                  "unsigned"
    ];
    regexes = [
      {"comment", ~r/\/\/.*/},
      {"reserved", ~r/#{Enum.join(keywords, "(?=[ :])+|(?=[ ])*")}/},
      {"string", ~r/\"[^\"]*\"/},
      {"specifier", ~r/<\w+[\.]*\w*>/},
      {"op", ~r/\+\+|--|&&|<<|>>|==|!=|<=|>=|<|>+-*\/%|\/\/|::|->|\*|endl/},
      {"function", ~r/\w+(?=\()/},
      {"identifier", ~r/\w+/},
      {"char", ~r/'.'/},
      {"number", ~r/\d+|\d+\.\d/},
      {"delimiter", ~r/[;{},():]/},
      {"directive", ~r/#|\./},
      {"space", ~r/\s/}
    ]
    {str, new_line} = test_regex(line, regexes, file, new_line, regexes)
    IO.inspect(str)
    if str != "" do
      validate_line(str, file, new_line)
    else
      write_line(file, new_line)
    end
  end

  def test_regex(str, [head | tail], file, new_line, regexes) do
    match = Regex.scan(elem(head, 1), str)
    if match != [] do
      [found_str | rest] = String.split(str, "#{Enum.at(match, 0)}", parts: 2)
      {a, found_str} = test_regex(found_str, regexes, file, "", regexes)
      IO.inspect(a)
      {Enum.join(rest), "#{new_line}#{found_str}#{a}#{to_html(elem(head, 0), Enum.at(match, 0))}"}
    else
      test_regex(str, tail, file, new_line, regexes)
    end
  end

  def test_regex(str, [], _file, new_line, _regexes) do
    {"", "#{new_line}#{str}"}
  end

  def to_html(type, token) do
    token = String.replace("#{token}", "<", "&lt;")
    if type == "space" do
      token
    else
      "<span class=\"#{type}\">#{token}</span>"
    end
  end

  def write_line(file, text) do
    fomated_text = String.replace(text, "\n", "")
    IO.puts(file, fomated_text)
  end

  def write_head(file) do
    File.stream!("assets/head.html")
    |> Enum.map(&IO.puts(file, &1))
  end

  def write_foot(file) do
    File.stream!("assets/foot.html")
    |> Enum.map(&IO.puts(file, &1))
  end

end


[in_file] = System.argv()
filename = Enum.at(String.split(in_file, "."), 0)
Lexer.read_file(in_file, "#{filename}.html")
