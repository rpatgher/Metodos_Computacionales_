# Basic implementation of Finite Automatons in Elixir
# An automaton is defined as:
# M = (Q, \Sigma, \delta, F, q_0)
# Remy Patgher
# 2024-04-16


defmodule DFA do

  # The automata argument is expressed as:
  # {delta, acceptm q0}
  def evaluate_1(string, automata) do
    string
    |> String.graphemes()
    |> eval_dfa(automata)
  end

  def eval_dfa([], {_delta, accept, state}) do
    Enum.member?(accept, state)
  end
  def eval_dfa([char | tail], {delta, accept, state}) do
    new_state = delta.(state, char)
    eval_dfa(tail,{delta, accept, new_state})
  end

  def delta_contains_db(state, char) do
    case state do
      :q0 -> case char do
        "a" -> :q3
        "b" -> :q0
        "c" -> :q0
        "d" -> :q1
      end
      :q1 -> case char do
        "a" -> :q3
        "b" -> :q2
        "c" -> :q0
        "d" -> :q1
      end
      :q2 -> case char do
        "a" -> :q4
        "b" -> :q2
        "c" -> :q2
        "d" -> :q2
      end
      :q3 -> case char do
        "a" -> :q3
        "b" -> :q0
        "c" -> :q0
        "d" -> :q5
      end
      :q4 -> case char do
        "a" -> :q4
        "b" -> :q2
        "c" -> :q2
        "d" -> :q5
      end
      :q5 -> :q5
    end
  end

  def delta_int_arithmetic(state, char) do
    case state do
      :start -> cond do
        is_sign(char) -> :sign
        is_digit(char) -> :int
        true -> :fail
      end
      :int -> cond do
        is_digit(char) -> :int
        is_operator(char) -> :op
        is_point(char) -> :point
        true -> :fail
      end
      :op -> cond do
        is_sign(char) -> :sign
        is_digit(char) -> :int
        true -> :fail
      end
      :sign -> cond do
        is_digit(char) -> :int
        true -> :fail
      end
      :point -> cond do
        is_digit(char) -> :int2
        true -> :fail
      end
      :int2 -> cond do
        is_digit(char) -> :int2
        is_operator(char) -> :op
        true -> :fail
      end
      :fail -> :fail
    end
  end

  def is_digit(char) do
    "0123456789"
    |> String.graphemes()
    |> Enum.member?(char)
  end

  def is_sign(char) do
    "+-"
    |> String.graphemes()
    |> Enum.member?(char)
  end

  def is_operator(char) do
    "+-*/%"
    |> String.graphemes()
    |> Enum.member?(char)
  end

  def is_point(char) do
    char == "."
  end

end
