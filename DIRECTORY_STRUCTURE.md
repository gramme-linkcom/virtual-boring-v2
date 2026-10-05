# 推奨ディレクトリ構成

このアプリは、カメラ認識だけでなく、Web UI、Unityゲームの起動・連携をまとめて扱う運用ツールです。`main` は起動の組み立てに留め、各機能を責務ごとに分けます。最初から空のフォルダを全部作らず、機能を実装するときに追加してください。

```text
.
├── CMakeLists.txt
├── CODING_GUIDELINES.md
├── README.md
├── config/
│   └── app.example.toml       # 設定例（実際のローカル設定はGit管理しない）
├── models/                    # モデル配布方法が決まるまで配置場所だけ予約
├── include/
│   └── vb/
│       ├── app/                # アプリ状態・ライフサイクル
│       ├── camera/             # カメラ入力・校正
│       ├── detection/          # YOLO推論・検出結果
│       ├── tracking/           # フレーム間追跡
│       ├── trajectory/         # 座標変換・速度/軌道推定
│       ├── game/               # Unity起動・終了・状態管理
│       ├── transport/          # Unityとのプロセス間通信/ソケット
│       └── web/                # Webサーバー/API
├── src/
│   ├── main.cpp
│   ├── app/
│   ├── camera/
│   ├── detection/
│   ├── tracking/
│   ├── trajectory/
│   ├── game/
│   ├── transport/
│   └── web/
│       ├── web_server.cpp
│       └── routes/             # APIルートが増えた段階で分割
├── web/                        # Web UI（HTML/CSS/JS等の静的ファイル）
├── tests/
│   ├── unit/
│   └── integration/
└── third_party/                # 手動同梱が必要な場合のみ。原則はCMake依存管理
```

## ディレクトリの使い分け

- `src/app`: カメラ、UI、Unityを起動・停止し、全体の状態遷移を調整します。個々の認識アルゴリズムは置きません。
- `src/web` と `web`: C++側のHTTPサーバー/APIと、ブラウザーで動くUI資産を分けます。Web画面からカメラやUnityを直接操作させず、アプリ層の操作/APIを通します。
- `src/camera`, `detection`, `tracking`, `trajectory`: 映像取得、推論、追跡、物理量推定の境界を保ちます。
- `src/game`: Unity実行ファイルの起動・終了やプロセス状態を扱います。
- `src/transport`: 投球イベント等の通信形式と送受信を扱います。Unityプロセス管理と通信方式の詳細を一つのクラスに混ぜません。
- `config`: 配布可能な設定例を置きます。実機ごとのパスや秘密情報を含む設定はコミットしません。
- `models`: サイズやライセンス、配布方法を確認してから運用を決めます。大きな重みファイルを安易にGitへ追加しません。
- `tests`: カメラやUnityがなくても確認できる座標変換・追跡・推定などから始めます。実機結合確認は別途手順を記録します。

既存の `src/ui` は、Webサーバー/APIの実装なら `src/web` に置くのが分かりやすいです。ブラウザー側のHTML/CSS/JSは `web/` に置きます。現在の `ui.cpp` は未完成なので、移動や改名は実装内容を固めてからで構いません。

この構成は将来の分割先を示すものです。現段階では `main.cpp` とWebサーバーなど、実際に使う箇所だけ用意し、他は機能追加時に作成します。
