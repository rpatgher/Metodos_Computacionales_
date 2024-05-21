#
# Remy Patgher
# 2024-05-17

defmodule Lexer do
  def read_file(in_filename, out_filename) do
    {:ok, out_file} = File.open(out_filename, [:write])
    write_head(out_file)
    File.stream!(in_filename)
    |> Enum.map(&validate_line(&1, out_file))

    write_foot(out_file)
    File.close(out_file)
  end

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
      {"reserved", ~r/#{Enum.join(keywords, "(?=[ :\(\)])+|(?=[ ])*")}/},
      {"null", ~r/NULL/},
      {"string", ~r/\"[^\"]*\"/},
      {"specifier", ~r/<\w+[\.]*\w*>/},
      {"op", ~r/\+\+|--|&&|<<|>>|==|!=|<=|>=|<|>+=-*\/%|\/\/|::|->|\*|endl|\+\=|-\=|\+|\=/},
      {"function", ~r/\w+(?=\()/},
      {"identifier", ~r/\w+/},
      {"char", ~r/'.'/},
      {"number", ~r/\d+|\d+\.\d/},
      {"delimiter", ~r/[;{},():]|\[|\]/},
      {"directive", ~r/#|\./},
      {"space", ~r/\s/}
    ]
    {processed_text, _} = process_text(line, regexes, "", regexes)
    write_line(file, processed_text)
  end

  defp process_text("", _regexes, acc, _original_regexes), do: {acc, ""}
  defp process_text(str, [], acc, _original_regexes), do: {acc <> str, ""}
  defp process_text(str, [head | tail], acc, original_regexes) do
    regex = elem(head, 1)
    case Regex.run(regex, str, capture: :first) do
      nil ->
        process_text(str, tail, acc, original_regexes)
      [match | _] ->
        {pre_match, post_match} = split_at_match(str, match)
        highlighted = to_html(elem(head, 0), match)
        {processed_pre, _} = process_text(pre_match, original_regexes, "", original_regexes)
        {processed_post, remaining_text} = process_text(post_match, original_regexes, "", original_regexes)
        {acc <> processed_pre <> highlighted <> processed_post, remaining_text}
    end
  end

  defp split_at_match(str, match) do
    [pre_match | post_match] = String.split(str, match, parts: 2)
    {pre_match, Enum.at(post_match, 0)}
  end

  defp to_html(type, token) do
    token = String.replace("#{token}", "<", "&lt;")
    if type == "space" do
      token
    else
      "<span class=\"#{type}\">#{token}</span>"
    end
  end

  defp write_line(file, text) do
    fomated_text = String.replace(text, "\n", "")
    IO.puts(file, fomated_text)
  end

  defp write_head(file) do
    File.stream!("assets/head.html")
    |> Enum.map(&IO.puts(file, &1))
  end

  defp write_foot(file) do
    File.stream!("assets/foot.html")
    |> Enum.map(&IO.puts(file, &1))
  end

  def measure(in_file, filename) do
    {time, _result} = :timer.tc(fn -> read_file(in_file, "#{filename}.html") end)
    IO.puts("Tiempo de ejecución: #{time / 1000000} segundos")
  end

end


[in_file] = System.argv()
filename = Enum.at(String.split(in_file, "."), 0)
# Lexer.measure(in_file, filename)
Lexer.read_file(in_file, "#{filename}.html")
