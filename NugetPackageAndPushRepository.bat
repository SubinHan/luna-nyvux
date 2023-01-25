del .\Nyvux\*.nupkg
nuget pack .\Nyvux\Nyvux.nuspec -OutputDirectory .\Nyvux
nuget push .\Nyvux\*.nupkg -Source https://api.nuget.org/v3/index.json -Apikey %NUGET_API_KEY%