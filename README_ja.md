# OpenPOS for OLE Common Control Objects Version 1.15 with Issue UPOS116-9  
これらは [UnifiedPOS Version 1.15][upos115] "Unified POS Retail Peripheral Architecture Version 1.15 formal/2020-01-05" に基づいた、OpenPOS for OLE(旧OLE for Retail POS:略称OPOS) Common Control Objects(共通CO) です。  

## 変更内容  
オリジナルの 1.14.001 版に対して、以下の対応を行っています。  

- ElectronicValueReader/WriterデバイスへCATデバイス機能を追加。  
- ElectronicValueReader/WriterデバイスのServiceTypeプロパティへEVRW_ST_CATを追加。[Issue UPOS116-9][UPOS1169]対応  
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
- 発行者のイニシャル(CRM/MCS)記述に変更者のイニシャル(KF)記述を追加します  
- EVRWSO用のOpos_Interfaces定義を、1.14.1用と1.15.0用の2つに分けました  
- Primary Interop Assemblyの追加  
- Install/Uninstall/ReRegister/UnRegisterバッチファイルの追加  


## インストールその他  
インストールは以下の手順で行ってください。  


- 既にインストールされているCCO(CommonControlObjects)があればアンインストールしておく。  
- 別途用意されているインストール用.zipファイルを、フォルダ構成を保ったまま展開する。  
- PIAをインストールする場合は、.NET Framework 3.5がインストールされていることを確認する。  
- 以下のいずれかのバッチファイルを管理者として実行して、CCO(およびPIA)をインストール・登録する。  
  - Install_CCOandPIA.bat  
  - Install_CCOonly.bat  

その他
- CCO(およびPIA)を再登録/登録解除するには以下のバッチファイルをバッチファイルを管理者として実行する。  
  - ReRegisterCCO.bat  
  - ReRegisterPIA.bat  
  - UnRegisterCCO.bat  
  - UnRegisterPIA.bat  
- CCO(およびPIA)のアンインストールおよびPIAのみのインストール/アンインストールには以下のバッチファイルを管理者として実行する。  
  - Uninstall_CCOandPIA.bat  
  - Uninstall_CCOonly.bat  
  - Install_PIAonly.bat  
  - Uninstall_PIAonly.bat  
- デバッグ版CCOのインストール/アンインストール/再登録/登録解除には以下のバッチファイルを管理者として実行する。  
  - Install_DbgCCO.bat  
  - Uninstall_DbgCCO.bat  
  - DbgReRegisterCCO.bat  
  - DbgUnRegisterCCO.bat  


## 既知の課題  
判明している課題には、以下のものがあります。

- Primary Interop Assemblyは1.14.001版およびそれ以前のOPOS for .NET Assemblies とは互換性がありません。  
- OPOSのデバイス定義レジストリのキー名称やデバイススタティスティクス項目名の定義文字列をDLLに含める方法が見当たらないのでC#ソースだけ作成しています。  
- OPOSのデバイス定義レジストリは32bit/64bit環境でそれぞれ独立して存在しており、それらを連携させたりまとめて取り扱う方法は見当たりません。  


## ライセンス  
[Apache License, Version 2.0](./LICENSE-2.0.txt) の下でライセンスされています。

元のバージョンは master ブランチに保持されます。  
元のコードのすべての権利はCurtiss Monroeに帰属します。  
最新のCommon Control Objects情報については、[official web site][opos]を確認してください。

[UPOS1169]: https://issues.omg.org/issues/spec/UPOS/1.15#issue-45536
[upos115]: https://www.omg.org/spec/UPOS/1.15/PDF
[opos]: http://monroecs.com/oposccos.htm
