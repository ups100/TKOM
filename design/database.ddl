CREATE TABLE "main"."read" (
    "ID" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    "IPMI_Version" REAL NOT NULL,
    "IPMIUtil_Version" REAL NOT NULL,
    "ISensor_Version" REAL NOT NULL,
    "BMC_Version" REAL NOT NULL,
    "NodeName" TEXT NOT NULL,
    "NodeIP" TEXT NOT NULL
);

CREATE TABLE "main"."log" (
    "readID" INTEGER  NOT NULL,
    "LogID" INTEGER NOT NULL,
    "SensorType" TEXT,
    "Et" INTEGER,
    "xx" INTEGER,
    "HexValues" TEXT,
    "Own" INTEGER,
    "SensorDescription" TEXT,
    "S_Num" INTEGER,
    "Typ" TEXT,
    "SensorStatus" TEXT,
    "IntelType" TEXT,
    "ReadingUnit" TEXT,
    "ReadingValue" REAL,
    PRIMARY KEY("readID", "LogID" )
);

