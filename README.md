# CppBoilerplateVS2013GtestGmockDoxygen
Boilerplate for c++ project written in C++ in Visual Studio 2013 with gtest and gmock TTD support and Doxygen documentation

## Зачем
Подготовка Solution для Test-Driven разработки с использованием gTest и gMock может занимать достаточно много времени. 

Этот проект нацелен на автоматизацию процесса создания решения для TTD разработки.

## Как пользоваться
* Клонировать к себе в рабочий каталог (например, с:\work\cpp) этот репозиторий.
* Переименовать получившуюся папку **CppBoilerplateVS2013GtestGmockDoxygen** в **NewProject**, где NewProject - имя проекта, который нужно создать 
* *Два раза* выполнить powershell-скрипт **RenameBoilerplate.ps1**
    - (пока вложенные файлы переименовываются только со второго раза, надо разобраться и починить)
* Всё, можно открывать NewProject.sln в VS2013 и пользоваться

## Как устроен NewProject.sln
В solution входят два проекта:
- NewProject
    + Основной проект. Компилируется в static library.
- NewProjectTest
    + Проект для тестирования. Линкуется к основному проекту. Использует gTest и gMock для тестирования.

### Предусловия
* Наличие в системе gMock (идёт вместе с gTest)
    - должны быть собраны файлы gmock.lib и gmockd.lib под x64 Multithreaded Debug Dll
    - пути к папкам, где они лежат должны быть прописаны в общесистемном property sheet в качестве Additional Library Directories
* В общесистемном property sheet лучше всего прописать и пути к gtest/include, gmock/include в качестве Additional Include Directories.

### Особенности
* Можно открыть solution и сразу запускать сборку. В результате этого
    - основной проект соберётся в static library NewProject.lib
    - проект для теситрования соберётся в консольное приложение NewProjectTest.exe и начнёт выполняться. Из коробки там есть несколько тестов gTest и gMock, которые тестируют некий простейший код, из NewProject.lib
* Оба проекта собираются в x64 с Runtime Multithreaded Dll (или соответственно Debug Dll)
* Сборка результатов обоих проектов производится в $SolutionDir/$Platform/Debug(Release)
    - Промежуточные файлы сборки попадают в temp/$SolutionDir/$Platform/Debug(Release)
