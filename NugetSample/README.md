# nuget native package

C++用のnugetパッケージを作ってみた

# ファイル構成

- {working directory}
    - build/
        - native/
            - include/
            - lib/
            - xxx.props
    - xxx.nuspec


- `nuget pack`時、`nuspec`ファイルと同階層(`working directory`)のファイルは`nupkg`に含まれてしまう

# 覚書

- nuspecファイルのひな形を作成する
    ```
    > nuget spec package-name
    ```
- nugetパッケージを作成する
    ```
    > nuget pack path/to/nuspec
    ```

# プロパティシート(*.props)テンプレート

```xml
<?xml version="1.0" encoding="utf-8"?>
<Project DefaultTargets="Build" ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
    <ItemDefinitionGroup>
        <ClCompile>
            <!-- プリプロセッサの定義 -->
            <PreprocessorDefinitions>xxx;%(PreprocessorDefinitions)</PreprocessorDefinitions>
            <!-- include path -->
            <AdditionalIncludeDirectories>$(MSBuildThisFileDirectory)include/;%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
        </ClCompile>
        <Link>
            <!-- library path -->
            <AdditionalLibraryDirectories>$(MSBuildThisFileDirectory)lib/$(Configuration)/;%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>
        </Link>
    </ItemDefinitionGroup>
    <!-- Configurationで設定を切り替える場合 -->
    <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
        <Link>
            <!-- debug library -->
            <AdditionalDependencies>xxxd.lib;%(AdditionalDependencies)</AdditionalDependencies>
        </Link>
    </ItemDefinitionGroup>
    <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
        <Link>
            <!-- release library -->
            <AdditionalDependencies>xxx.lib;%(AdditionalDependencies)</AdditionalDependencies>
        </Link>
    </ItemDefinitionGroup>
</Project>
```

# 参考

- [C++プロジェクトでNuGetを使ってみようよ！（Vol. 2：パッケージ作成編）](https://qiita.com/nia_tn1012/items/0815e1f493ac49d20d41)
- [.nuspec リファレンス](https://docs.microsoft.com/ja-jp/nuget/reference/nuspec)
- [MSBuild の予約済みおよび既知のプロパティ](https://docs.microsoft.com/ja-jp/visualstudio/msbuild/msbuild-reserved-and-well-known-properties?view=vs-2015)
- [native のnugetパッケージを作る](https://qiita.com/jugemjugemu/items/4398d2847e9511aac335)
