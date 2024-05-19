defmodule ValidateTextFile do
  def validate(txt) do
    File.stream!(txt)
    |> Enum.map(&String.trim/1)
    |> Enum.map(fn(n) -> Regex.scan(~r/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/u, n) end)
  end
end
