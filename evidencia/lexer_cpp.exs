# Program that reads a file and generates an HTML file with
# the syntax highlighted of a C++ file using Elixir and Regex
#
# The program uses the File module to read the file and the Regex
# module to validate each line of code and generate the HTML file
#
# Remy Patgher
# 2024-05-17

defmodule Lexer do
  @doc """
  Reads a C++ file and generates an HTML file with the syntax highlighted
  """
  def read_file(in_filename, out_filename) do
    {:ok, out_file} = File.open(out_filename, [:write])
    write_head(out_file)
    # Reads the file and validates each line
    File.stream!(in_filename)
    |> Enum.map(&validate_line(&1, out_file))

    write_foot(out_file)
    File.close(out_file)
  end

  # Validates each line of code and writes it to the output file with the syntax highlighted
  defp validate_line(line, file) do
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
                  "unsigned",
                  "new"
    ];
    regexes = [
      {"comment", ~r/\/\/.*/},
      {"reserved", ~r/#{Enum.join(keywords, "(?=[ :\(\)])+|(?=\b)*")}/},
      {"null", ~r/NULL/},
      {"string", ~r/\"[^\"]*\"/},
      {"specifier", ~r/<\w+[\.]*\w*>/},
      {"op", ~r/\+\+|--|&&|<<|>>|==|!=|<=|>=|<|>+=-*\/%|\/\/|::|->|\*|endl|\+\=|-\=|\+|\=/},
      {"number", ~r/\d+|\d+\.\d/},
      {"function", ~r/\w+(?=\()/},
      {"identifier", ~r/\w+/},
      {"char", ~r/'.'/},
      {"delimiter", ~r/[;{},():]|\[|\]/},
      {"directive", ~r/#|\./},
      {"space", ~r/\s/}
    ]
    # Process the line and write it to the file
    {processed_text, _} = process_text(line, regexes, "", regexes)
    write_line(file, processed_text)
  end


  # Processes the text evaluating each regex on the string passed
  # to the function and returns the string with the syntax highlighted
  # of a line of code
  defp process_text("", _regexes, acc, _original_regexes), do: {acc, ""}
  defp process_text(str, [], acc, _original_regexes), do: {acc <> str, ""}
  defp process_text(str, [head | tail], acc, original_regexes) do
    # Take the current regex and evaluate it on the string
    regex = elem(head, 1)
    case Regex.run(regex, str, capture: :first) do
      nil ->
        # if there is no match, continue with the next regex
        process_text(str, tail, acc, original_regexes)
      [match | _] ->
        # if there is a match, split the string at the match and process the
        # text before the match, the match and the text after the match
        {pre_match, post_match} = split_at_match(str, match)
        highlighted = to_html(elem(head, 0), match)
        # Process the text before the match and the text after the match
        {processed_pre, _} = process_text(pre_match, original_regexes, "", original_regexes)
        # Process the text after the match
        {processed_post, remaining_text} = process_text(post_match, original_regexes, "", original_regexes)
        # When all the text is processed, return the text with the syntax highlighted
        {acc <> processed_pre <> highlighted <> processed_post, remaining_text}
    end
  end

  # Splits the string at the first ocurrence of the match of a string
  # and returns a tuple with the string before the match and the string
  # after the match
  defp split_at_match(str, match) do
    # Split the string at the first ocurrence of the match
    [pre_match | post_match] = String.split(str, match, parts: 2)
    # Return the string before the match and the string after the match
    {pre_match, Enum.at(post_match, 0)}
  end

  # Returns the HTML representation of a token
  defp to_html(type, token) do
    token = String.replace("#{token}", "<", "&lt;")
    if type == "space" do
      token
    else
      "<span class=\"#{type}\">#{token}</span>"
    end
  end

  # Writes a line to the HTML file
  defp write_line(file, text) do
    fomated_text = String.replace(text, "\n", "")
    IO.puts(file, fomated_text)
  end

  # Writes the head of the HTML file
  defp write_head(file) do
    File.stream!("html/head.html")
    |> Enum.map(&IO.puts(file, &1))
  end

  # Writes the foot of the HTML file
  defp write_foot(file) do
    File.stream!("html/foot.html")
    |> Enum.map(&IO.puts(file, &1))
  end

  @doc """
  Measures the time it takes to read a file
  """
  def measure(in_file, filename) do
    {time, _result} = :timer.tc(fn -> read_file(in_file, "#{filename}.html") end)
    IO.puts("Tiempo de ejecución: #{time / 1000000} segundos")
  end
end


[in_file] = System.argv()
filename = Enum.at(String.split(in_file, "."), 0)
# Lexer.measure(in_file, filename)
Lexer.read_file(in_file, "#{filename}.html")
