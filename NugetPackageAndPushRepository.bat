del .\Nyvux\*.nupkg
nuget pack .\Nyvux\Nyvux.nuspec -OutputDirectory .\Nyvux
nuget push .\Nyvux\*.nupkg -Source https://api.nuget.org/v3/index.json -Apikey oy2a7nvz4ftru4ai6ofaoulgksfqhcxepphas3ysn6jnhm