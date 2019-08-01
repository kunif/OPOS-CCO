# OpenPOS for OLE Common Control Objects Version 1.15 Beta2 12/2018  
これらは標準化策定作業中の [UnifiedPOS Version 1.15][upos115] "Unified POS Retail Peripheral Architecture FTF - Beta 2  dtc/18-12-20" に基づいた、OpenPOS for OLE(旧OLE for Retail POS:略称OPOS) Common Control Objects(共通CO) の試作版です。  

## 変更内容  
オリジナルの 1.14.001 版に対して、以下の対応を行っています。  

仕様策定作業中の版に基づいた対応を行っています。  

- ElectronicValueReader/WriterデバイスへCATデバイス機能を追加。  
- FiscalPrinterデバイスのCountryCode, DateTypeプロパティへ値を追加。  

上記に加えて、以下の対応を行っています。  


- 開発環境を Visual Studio 2008 から Visual Studio Community 2019 に変更。  
  - プラットフォームツールセットは Visual Studio 2019(v142)  
  - Windows SDK バージョンは 10.0  
  - 改造前の atlcom.h を、Visual Studio Community 2019のフォルダにあるものに変更  
  - .h ファイルのインクルードガードを #ifndef \_\_XXXX\_H\_\_ から #pragma once に変更  
  - タイプライブラリの名前の頭にOPOSを付け、ビルド結果として残すように変更  
  - .map, .pdb ファイルも、ビルド結果として残すように変更  
- サポート版数を Windows7 以後に変更  
  Windows 2000, XP, Vista はサポート対象ではなくなりました。  
- デバッグ版のトレース機能を RCSTrace から \_FILETRACE に変更  
- Intel/AMD 64bitのサポート追加  
- OPOS内部定数定義をdll化して追加  
- OPOS ServiceObject 用のインタフェース定義例をdll化して追加  
- 著作権記述の年表記を更新  


## インストール  
インストールは以下の手順で行ってください。  


- 対象ファイル用に(以下のような)適当なフォルダを作成し、ファイルをコピーする。  
  - ファイルコピー元  
    - OPOS 32bit : OCX\\Win32\\Release フォルダの \*.dll および \*.ocx  
    - OPOS 64bit : OCX\\x64\\Release フォルダの \*.dll および \*.ocx  
  - OPOS 32bit ファイルコピー先  
    - 64bitOS時 : C:\\Program Files (x86)\\OPOS\\CommonCO115フォルダ  
    - 32bitOS時 : C:\\Program Files\\OPOS\\CommonCO115フォルダ  
  - OPOS 64bit ファイルコピー先  
    - 64bitOS : C:\\Program Files\\OPOS\\CommonCO115フォルダ  


- RegSvr32.exeを管理者として実行し、DLLをレジストリ登録する。  
  - 64bitOS時は先行処理 : C:\\Windows\\SysWOW64\\cmd.exe を管理者として実行。  
  - C:\\Program Files (x86)\\OPOS\\CommonCO115フォルダに移動。  
  - For %I in (\*.dll,\*.ocx) do RegSvr32 /s %I を実行。  
  - 32bit/64bit両OS : C:\\Windows\\System32\\cmd.exe を管理者として実行。  
  - C:\\Program Files\\OPOS\\CommonCO115フォルダに移動。  
  - For %I in (\*.dll,\*.ocx) do RegSvr32 /s %I を実行。  
  - 両方とも正常に実行された表示を確認してcmd.exeを終了。  


## 既知の課題  
判明している課題には、以下のものがあります。

- OPOS for .NET Assemblies との連携・同期が出来た方が良いですが、それに関連することは何もしていません。  
- OPOS ServiceObject 用のインタフェース定義dllは、次の1.16版等でインタフェースの追加があった場合に互換性問題が発生する可能性があり、正式版には入らないかもしれません。  
- インストーラは作成していません。
- OPOSのデバイス定義レジストリのキー名称やデバイススタティスティクス項目名の定義文字列をDLLに含める方法が見当たらないのでC#ソースだけ作成しています。  
- OPOSのデバイス定義レジストリは32bit/64bit環境でそれぞれ独立して存在しており、それらを連携させたりまとめて取り扱う方法は見当たりません。  


## ライセンス  
[Apache License, Version 2.0](./LICENSE-2.0.txt) の下でライセンスされています。

元のバージョンは master ブランチに保持されます。  
元のコードのすべての権利はCurtiss Monroeに帰属します。  
最新のCommon Control Objects情報については、[official web site][opos]を確認してください。

[upos115]: https://www.omg.org/spec/UPOS/1.15/Beta2/PDF
[opos]: http://monroecs.com/oposccos.htm
