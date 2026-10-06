# バーチャルボーリング運用ツール

カメラによるボール認識と軌道推定、Web UIからの状態確認・操作、Unityゲームの起動と連携を行うC++アプリです。

## 開発ドキュメント

- [C++コーディング規約](CODING_GUIDELINES.md)
- [ディレクトリ構成ガイド](DIRECTORY_STRUCTURE.md)

構成は実装の進行に合わせて追加します。未実装機能のフォルダを先に大量に作る必要はありません。

## Windowsでの開発環境

MinGW-w64（g++、CMake、Ninja、OpenCV 入り）をまとめた zip を使います。インストーラーは不要です。

1. [Releases](https://github.com/gramme-linkcom/virtual-boring-toolchain) から `toolchain-ucrt64.zip` をダウンロードして展開します（例：`C:\vb-toolchain`）。
2. 展開先の `ucrt64\bin` を環境変数 `Path` に追加します。
3. 新しいターミナルで、次のコマンドでバージョンが表示されれば完了です。
```

```

## ビルドの方法について
```
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B build
cmake --build build
cd build
```
