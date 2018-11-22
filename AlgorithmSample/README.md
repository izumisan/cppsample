# algorithmサンプル

# 判定・検索

|メソッド|説明|
|---|---|
|all_of|全ての要素が指定条件を満たす場合true|
|any_of|指定条件を満たす要素が1つでも存在する場合true|
|none_of|全ての要素が指定条件を満たさない場合true|
|for_each||
|find|指定要素のイテレータを返す|
|find_if|指定条件を満たす要素のイテレータを返す|
|find_if_not|指定条件を満たさない要素のイテレータを返す|
|find_first_of|指定した集合の1つに一致する最初の要素のイテレータを返す|
|search|指定したシーケンスの最初の要素のシーケンスを返す|
|find_end|指定したシーケンスの最後の要素のシーケンスを返す|
|count|指定した要素の数を返す|
|count_if|指定条件を満たす要素の数を返す|
|equal|指定したシーケンスと等しい場合true|
|mismatch|指定したシーケンスと異なる要素のイテレータ（各イテレータのペア）を返す|

# ソート

|メソッド|説明|
|---|---|
|`sort`|ソート|
|`stable_sort`|安定ソート|
|`partial_sort`|部分ソート|
|`partial_sort_copy`|部分ソートし、ソート結果をコピーする|
|`is_sorted`|ソート済みか否かを判定する|
|`is_sorted_until`|ソート済みか否かを判定し、ソートされていない位置のイテレータを取得する|
|`nth_element`|指定要素より小さい要素が前に来るように並び替える|

# 二分探索

|メソッド|説明|
|---|---|
|`lower_bound`||
|`upper_bound`||
|`equal_range`||
|`binary_search`||

# 集合

|メソッド|説明|
|---|---|
|`set_union`|和集合|
|`set_intersection`|積集合|
|`set_difference`|差集合|
|`set_symmetric_difference`|互いに素な集合|
|`includes`|一方が他方に含まれているか否か|

# 最小値・最大値

|メソッド|説明|
|---|---|
|`min`|最小値を取得する|
|`max`|最大値を取得する|
|`minmax`|最小値と最大値を取得する|
|`min_element`|最小値へのイテレータを取得する|
|`max_element`|最大値へのイテレータを取得する|
|`minmax_element`|最小値・最大値へのイテレータを取得する|
|`clamp`||


# リンク

- [algorithm - C++日本語リファレンス](https://cpprefjp.github.io/reference/algorithm.html)
