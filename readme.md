# バーチャルボーリング運用ツール

カメラによるボール認識と軌道推定、Web UIからの状態確認・操作、Unityゲームの起動と連携を行うC++アプリです。

## 開発ドキュメント

- [C++コーディング規約](CODING_GUIDELINES.md)
- [ディレクトリ構成ガイド](DIRECTORY_STRUCTURE.md)

構成は実装の進行に合わせて追加します。未実装機能のフォルダを先に大量に作る必要はありません。

## ビルドの方法について
```
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B build
cmake --build build
cd build
```
