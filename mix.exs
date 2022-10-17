defmodule SubtitleMixer.MixProject do
  use Mix.Project

  def project do
    [
      app: :subtitle_mixer,
      version: "0.1.0",
      elixir: "~> 1.14",
      start_permanent: Mix.env() == :prod,
      compilers: [:unifex, :bundlex] ++ Mix.compilers(),
      deps: deps()
    ]
  end

  # Run "mix help compile.app" to learn about applications.
  def application do
    [
      extra_applications: [:logger]
    ]
  end

  # Run "mix help deps" to learn about dependencies.
  defp deps do
    [
      {:unifex, "~> 1.0"},
      {:kim_subtitle, github: "kim-company/kim_subtitle"},
      {:benchee, "~> 1.1.0", only: :test}
    ]
  end
end
