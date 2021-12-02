# OpenPOS for OLE Common Control Objects Version 1.16  
これらは [UnifiedPOS Version 1.16][upos116] "Unified POS Retail Peripheral Architecture Version 1.16" に基づいた、OpenPOS for OLE(旧OLE for Retail POS:略称OPOS) Common Control Objects(共通CO) です。  

## 変更内容  
1.15.000 版に対して、以下の対応を行っています。  

- Lightsデバイス、POSPowerデバイスへRetail Communication Service Device対応機能を追加。  
- Retail Communication Service Deviceの9つの新デバイスカテゴリーを追加。  
  - DeviceMonitor  
  - GestureControl  
  - GraphicDisplay  
  - IndividualRecognition  
  - SoundPlayer  
  - SoundRecorder  
  - SpeechSynthesis  
  - VideoCapture  
  - VoiceRecognition  
- 共通CO 1.15.000 版用に作成した.NETアプリケーション向けにPublisher Policyファイルを追加。  
- 開発環境を Visual Studio Community 2019 から Visual Studio Community 2022 に変更。  
  - プラットフォームツールセットは Visual Studio 2022(v143)  
  - Windows SDK バージョンは 10.0  
  - 改造前の atlcom.h を、Visual Studio Community 2022のフォルダにあるものに変更  
- LightsとPOSPowerのSO用Opos_Interfaces定義を、1.15.0用と1.16.0用の2つに分けました  


## インストールその他  
インストールは以下の手順で行ってください。  


- 既にインストールされているCCO(CommonControlObjects)があればアンインストールしておく。  
- 別途用意されているインストール用.zipファイルを、フォルダ構成を保ったまま展開する。  
- PIAをインストールする場合は、.NET Framework 3.5がインストールされていることを確認する。  
- 以下のいずれかのバッチファイルを管理者として実行して、CCO(およびPIAとPublisher Policy)をインストール・登録する。  
  - Install_CCOandPIA.bat  
  - Install_CCOonly.bat  

その他
- CCO(およびPIAとPublisher Policy)を再登録/登録解除するには以下のバッチファイルをバッチファイルを管理者として実行する。  
  - ReRegisterCCO.bat  
  - ReRegisterPIA.bat  
  - UnRegisterCCO.bat  
  - UnRegisterPIA.bat  
- CCO(およびPIAとPublisher Policy)のアンインストールおよびPIAとPublisher Policyのみのインストール/アンインストールには以下のバッチファイルを管理者として実行する。  
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

- Primary Interop AssemblyとPublisher Policyは1.14.001版およびそれ以前のOPOS for .NET Assemblies とは互換性がありません。  
- OPOSのデバイス定義レジストリのキー名称やデバイススタティスティクス項目名の定義文字列をDLLに含める方法が見当たらないのでC#ソースだけ作成しています。  
- OPOSのデバイス定義レジストリは32bit/64bit環境でそれぞれ独立して存在しており、それらを連携させたりまとめて取り扱う方法は見当たりません。  


## ライセンス  
[Apache License, Version 2.0](./LICENSE-2.0.txt) の下でライセンスされています。

元のバージョンは master ブランチに保持されます。  
元のコードのすべての権利はCurtiss Monroeに帰属します。  
最新のCommon Control Objects情報については、[official web site][opos]を確認してください。

[upos116]: https://www.omg.org/spec/UPOS/1.16/Beta1/PDF
[opos]: http://monroecs.com/oposccos.htm
