# nuget native package

C++用のnugetパッケージを作ってみた

# 覚書

- nuspecファイルのひな形を作成する
    ```
    > nuget spec package-name
    ```
- nugetパッケージを作成する
    ```
    > nuget pack path/to/nuspec
    ```
- `nuget pack`時、`nuspec`ファイルと同階層のファイルは全て`nupkg`に含めてしまう？
    - `nuspec`ファイルと同じ場所に`nuget.exe`を置いていたら、`nupkg`ファイルに`nuget.exe`が含まれていた

# 参考

- [C++プロジェクトでNuGetを使ってみようよ！（Vol. 2：パッケージ作成編）](https://qiita.com/nia_tn1012/items/0815e1f493ac49d20d41)
- [.nuspec リファレンス](https://docs.microsoft.com/ja-jp/nuget/reference/nuspec)
- [MSBuild の予約済みおよび既知のプロパティ](https://docs.microsoft.com/ja-jp/visualstudio/msbuild/msbuild-reserved-and-well-known-properties?view=vs-2015)
- [native のnugetパッケージを作る](https://qiita.com/jugemjugemu/items/4398d2847e9511aac335)
