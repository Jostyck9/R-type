if ( -not (Test-Path -Path '.\build\' -PathType Container) ) { & "mkdir" build }
& "cd" build
& "conan.exe" install ..
& "cmake" ..