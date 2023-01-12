del .\Nyvux\*.nupkg
nuget pack .\Nyvux\Nyvux.nuspec -OutputDirectory .\Nyvux
move .\Nyvux\*.nupkg D:\nuget-source