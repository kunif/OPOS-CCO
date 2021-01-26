using System.Runtime.InteropServices;

[ComVisible(false)]
internal static class OposRegKey
{
    //////////////////////////////////////////////////////////////////////
    //
    // Registry Key Strings From Opos.hi
    //
    //   General header file for OPOS Control Objects and Service Objects.
    //
    //////////////////////////////////////////////////////////////////////
    // Registry Keys
    //////////////////////////////////////////////////////////////////////

    // OPOS_ROOTKEY is the key under which all OPOS Service Object keys
    //   and values are placed.  This key will contain device class keys.
    //   (The base key is HKEY_LOCAL_MACHINE.)
    internal const string OPOS_ROOTKEY = "SOFTWARE\\OLEforRetail\\ServiceOPOS";

    // Device Class Keys
    //   Release 1.0
    internal const string OPOS_CLASSKEY_CASH = "CashDrawer";
    internal const string OPOS_CLASSKEY_COIN = "CoinDispenser";
    internal const string OPOS_CLASSKEY_TOT = "HardTotals";
    internal const string OPOS_CLASSKEY_LOCK = "Keylock";
    internal const string OPOS_CLASSKEY_DISP = "LineDisplay";
    internal const string OPOS_CLASSKEY_MICR = "MICR";
    internal const string OPOS_CLASSKEY_MSR = "MSR";
    internal const string OPOS_CLASSKEY_PTR = "POSPrinter";
    internal const string OPOS_CLASSKEY_SCAL = "Scale";
    internal const string OPOS_CLASSKEY_SCAN = "Scanner";
    internal const string OPOS_CLASSKEY_SIG = "SignatureCapture";
    //   Release 1.1
    internal const string OPOS_CLASSKEY_KBD = "POSKeyboard";
    //   Release 1.2
    internal const string OPOS_CLASSKEY_CHAN = "CashChanger";
    internal const string OPOS_CLASSKEY_TONE = "ToneIndicator";
    //   Release 1.3
    internal const string OPOS_CLASSKEY_BB = "BumpBar";
    internal const string OPOS_CLASSKEY_FPTR = "FiscalPrinter";
    internal const string OPOS_CLASSKEY_PPAD = "PINPad";
    internal const string OPOS_CLASSKEY_ROD = "RemoteOrderDisplay";
    //   Release 1.4
    internal const string OPOS_CLASSKEY_CAT = "CAT";
    //   Release 1.5
    internal const string OPOS_CLASSKEY_PCRW = "PointCardRW";
    internal const string OPOS_CLASSKEY_PWR = "POSPower";
    //   Release 1.7
    internal const string OPOS_CLASSKEY_CHK = "CheckScanner";
    internal const string OPOS_CLASSKEY_MOTION = "MotionSensor";
    //   Release 1.8
    internal const string OPOS_CLASSKEY_SCRW = "SmartCardRW";
    //   Release 1.10
    internal const string OPOS_CLASSKEY_BIO = "Biometrics";
    internal const string OPOS_CLASSKEY_EJ = "ElectronicJournal";
    //   Release 1.11
    internal const string OPOS_CLASSKEY_BACC = "BillAcceptor";
    internal const string OPOS_CLASSKEY_BDSP = "BillDispenser";
    internal const string OPOS_CLASSKEY_CACC = "CoinAcceptor";
    internal const string OPOS_CLASSKEY_IMG = "ImageScanner";
    //   Release 1.12
    internal const string OPOS_CLASSKEY_BELT = "Belt";
    internal const string OPOS_CLASSKEY_EVRW = "ElectronicValueRW";
    internal const string OPOS_CLASSKEY_GATE = "Gate";
    internal const string OPOS_CLASSKEY_ITEM = "ItemDispenser";
    internal const string OPOS_CLASSKEY_LGT = "Lights";
    internal const string OPOS_CLASSKEY_RFID = "RFIDScanner";
    //   Release 1.16
    internal const string OPOS_CLASSKEY_DMON = "DeviceMonitor";
    internal const string OPOS_CLASSKEY_GCTL = "GestureControl";
    internal const string OPOS_CLASSKEY_GDSP = "GraphicDisplay";
    internal const string OPOS_CLASSKEY_IRCG = "IndividualRecognition";
    internal const string OPOS_CLASSKEY_SPLY = "SoundPlayer";
    internal const string OPOS_CLASSKEY_SREC = "SoundRecorder";
    internal const string OPOS_CLASSKEY_SPCH = "SpeechSynthesis";
    internal const string OPOS_CLASSKEY_VCAP = "VideoCapture";
    internal const string OPOS_CLASSKEY_VRCG = "VoiceRecognition";

    // OPOS_ROOTKEY_PROVIDER is the key under which a Service Object
    //   provider may place provider-specific information.
    //   (The base key is HKEY_LOCAL_MACHINE.)
    internal const string OPOS_ROOTKEY_PROVIDER = "SOFTWARE\\OLEforRetail\\ServiceInfo";
}
