# Program that calculates the sum of all prime numbers between 1 and max sequentially and in parallel.
#
# Remy Patgher Aguilar
# 09/06/2024
#

defmodule Hw.Primes do
  @doc """
  It sums all prime numbers between 1 and max.
  It receives if the sum must be computed with parallelism or sequentially.
  """
  def get_sum_primes(max, parallel) do
    if parallel do
      time = :timer.tc(fn -> sum_primes_parallel(max, System.schedulers_online()) end ) |> elem(0) |> Kernel./(1_000_000)
      IO.puts("Time: #{time} seconds")
    else
      time = :timer.tc(fn -> sum_primes(max) end ) |> elem(0) |> Kernel./(1_000_000)
      IO.puts("Time: #{time} seconds")
    end
  end

  def get_sum_primes_speedup(max) do
    time_seq = :timer.tc(fn -> sum_primes(max) end ) |> elem(0) |> Kernel./(1_000_000)
    time_par = :timer.tc(fn -> sum_primes_parallel(max, System.schedulers_online()) end ) |> elem(0) |> Kernel./(1_000_000)
    IO.puts("Time sequential: #{time_seq} seconds")
    IO.puts("Time parallel: #{time_par} seconds")
    IO.puts("Speedup: #{time_seq/time_par}")
  end

  @doc """
  Function that returns the sum of all prime numbers between 1 and max sequentially.
  """
  def sum_primes(max) do
    IO.puts("The total sum of primes is #{do_sum_primes(1, max)}")
  end

  @doc """
  Function that returns the sum of all prime numbers between 1 and max in parallel.
  """
  def sum_primes_parallel(max, cores) do
    IO.puts("Cores: #{cores}")
    result =
      1..cores
      |> Enum.map(fn i -> Task.async(fn -> do_sum_primes(div((i-1)*max, cores)+1, div(i*max, cores)) end) end)
      |> Enum.map(&Task.await(&1, :infinity))
      |> Enum.reduce(0, &(&1 + &2))
    IO.puts("The total sum of primes is #{result}")
  end

  @doc """
  Function that returns the sum of all prime numbers between min and max.
  """
  def do_sum_primes(min, max) do
    nums = for i <- min..max do
      if is_prime(i) do
        i
      else
        0
      end
    end
    sum = Enum.reduce(nums, &(&1 + &2))
    IO.puts("The sum of primes between #{min} and #{max} is #{sum}")
    sum
  end

  @doc """
  Function that returns if a number is prime or not.
  """
  def is_prime(n) when n < 2, do: false
  def is_prime(2), do: true
  def is_prime(n) do
    2..(ceil(:math.sqrt(n)))
    |> Enum.all?(fn i ->
      if rem(n, i) == 0 do
        false
      else
        true
      end
    end)
  end
end
