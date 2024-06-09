defmodule Hw.Primes do
  def get_sum_primes(max, parallel) do
    if parallel do
      time = :timer.tc(fn -> sum_primes_parallel(max, System.schedulers_online()) end ) |> elem(0) |> Kernel./(1_000_000)
      IO.puts("Time: #{time} seconds")
    else
      time = :timer.tc(fn -> sum_primes(max) end ) |> elem(0) |> Kernel./(1_000_000)
      IO.puts("Time: #{time} seconds")
    end
  end

  def sum_primes(max) do
    IO.puts("The total sum of primes is #{do_sum_primes(1, max)}")
  end

  def sum_primes_parallel(max, cores) do
    IO.puts("Cores: #{cores}")
    result =
      1..cores
      |> Enum.map(fn i -> Task.async(fn -> do_sum_primes(div((i-1)*max, cores)+1, div(i*max, cores)) end) end)
      |> Enum.map(&Task.await(&1, :infinity))
      |> Enum.reduce(0, &(&1 + &2))
    IO.puts("The total sum of primes is #{result}")
  end

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
