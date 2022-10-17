defmodule Subtitle.Mixer.MixProject do
  use Mix.Project

  def project do
    [
      app: :subtitle_mixer,
      version: "0.1.0",
      elixir: "~> 1.14",
      start_permanent: Mix.env() == :prod,
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
      {:kim_subtitle, github: "kim-company/kim_subtitle"}
    ]
  end
end
