#
#
# Remy Patgher
# 2024-06-04

defmodule Parallel do
  @num_threads 5

  def thread_func(id) do
    IO.puts("I am #{id}")
  end

  def main() do
    IO.puts("STARTING MAIN THREAD")
    # Launch a new process to run a function
    task = Task.async(fn -> thread_func("Test") end)
    # IO.inspect(task, label: "Task")
    Task.await(task)
    IO.puts("FINISHING MAIN THREAD")
  end

  def multi() do
    IO.puts("STARTING MAIN THREAD")
    # Launch a many processes to run a function
    t1 = Task.async(fn -> thread_func("Test 1") end)
    t2 = Task.async(fn -> thread_func("Test 2") end)
    t3 = Task.async(fn -> thread_func("Test 3") end)
    Task.await(t1)
    Task.await(t2)
    Task.await(t3)
    IO.puts("FINISHING MAIN THREAD")
  end

  def loops() do
    IO.puts("STARTING MAIN THREAD")
    # Launch a many processes to run a function
    tasks = for i <- 1..@num_threads do
      Task.async(fn -> thread_func("Test #{i}") end)
    end
    for task <- tasks do
      Task.await(task)
    end
    IO.puts("FINISHING MAIN THREAD")
  end

  def maps() do
    1..@num_threads
    |> Enum.map(fn i -> Task.async(fn -> thread_func("Test #{i}") end) end)
    |> Enum.map(&Task.await(&1))
  end
end
