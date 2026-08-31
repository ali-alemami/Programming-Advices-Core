-- =====================================================================
-- Course 17: Vehicle Makes Database - 50 Analytical SQL Problems
-- Database: VehicleMakesDB / VehicleDetails View
-- Topics: Aggregations, Window Functions, Filtering, Subqueries, Having, In, Top
-- =====================================================================

USE VehicleMakesDB;
GO

-- Problem 1: Create Master View
IF OBJECT_ID('VehicleMasterView', 'V') IS NOT NULL DROP VIEW VehicleMasterView;
GO
CREATE VIEW VehicleMasterView AS
SELECT 
    V.VehicleID, V.MakeID, M.Make, V.ModelID, MO.Model, 
    V.SubModelID, SM.SubModelName, V.BodyID, B.BodyName,
    V.Vehicle_Display_Name, V.Year, V.DriveTypeID, DT.DriveTypeName,
    V.Engine, V.Engine_CC, V.Engine_Cylinders, V.Engine_Liter_Display,
    V.FuelTypeID, FT.FuelTypeName, V.NumDoors
FROM VehicleDetails V
JOIN Makes M ON V.MakeID = M.MakeID
JOIN MakeModels MO ON V.ModelID = MO.ModelID
JOIN SubModels SM ON V.SubModelID = SM.SubModelID
JOIN Bodies B ON V.BodyID = B.BodyID
JOIN DriveTypes DT ON V.DriveTypeID = DT.DriveTypeID
JOIN FuelTypes FT ON V.FuelTypeID = FT.FuelTypeID;
GO

-- Problem 2: Get all vehicles made between 1950 and 2000
SELECT * FROM VehicleDetails WHERE Year BETWEEN 1950 AND 2000;

-- Problem 3: Get number of vehicles made between 1950 and 2000
SELECT COUNT(*) AS NumberOfVehicles FROM VehicleDetails WHERE Year BETWEEN 1950 AND 2000;

-- Problem 4: Vehicles made between 1950 and 2000 per make ordered by count desc
SELECT Make, COUNT(*) AS NumberOfVehicles 
FROM VehicleDetails 
WHERE Year BETWEEN 1950 AND 2000 
GROUP BY Make 
ORDER BY NumberOfVehicles DESC;

-- Problem 5: Makes manufacturing > 12000 vehicles between 1950 and 2000
SELECT Make, COUNT(*) AS TotalVehicles 
FROM VehicleDetails 
WHERE Year BETWEEN 1950 AND 2000 
GROUP BY Make 
HAVING COUNT(*) > 12000 
ORDER BY TotalVehicles DESC;

-- Problem 6: Add Total Vehicles column beside each make count (Window Function)
SELECT Make, COUNT(*) AS NumberOfVehicles, SUM(COUNT(*)) OVER() AS TotalAllVehicles 
FROM VehicleDetails 
WHERE Year BETWEEN 1950 AND 2000 
GROUP BY Make 
ORDER BY NumberOfVehicles DESC;

-- Problem 7: Calculate Percentage of Market Share per Make
SELECT 
    Make, 
    COUNT(*) AS NumberOfVehicles, 
    SUM(COUNT(*)) OVER() AS TotalAllVehicles,
    CAST(COUNT(*) * 100.0 / SUM(COUNT(*)) OVER() AS DECIMAL(5, 2)) AS [Percentage]
FROM VehicleDetails 
WHERE Year BETWEEN 1950 AND 2000 
GROUP BY Make 
ORDER BY NumberOfVehicles DESC;

-- Problem 8: Make, FuelTypeName and Number of Vehicles per FuelType per Make
SELECT Make, FuelTypeName, COUNT(*) AS TotalVehicles 
FROM VehicleDetails 
GROUP BY Make, FuelTypeName 
ORDER BY Make ASC, TotalVehicles DESC;

-- Problem 9: Get all vehicles that run with GAS
SELECT * FROM VehicleDetails WHERE FuelTypeName = 'GAS';

-- Problem 10: Distinct Makes that run with GAS
SELECT DISTINCT Make FROM VehicleDetails WHERE FuelTypeName = 'GAS';

-- Problem 11: Total number of distinct Makes running with GAS
SELECT COUNT(DISTINCT Make) AS TotalMakesWithGAS FROM VehicleDetails WHERE FuelTypeName = 'GAS';

-- Problem 12: Count vehicles by Make ordered from high to low
SELECT Make, COUNT(*) AS NumberOfVehicles 
FROM VehicleDetails 
GROUP BY Make 
ORDER BY NumberOfVehicles DESC;

-- Problem 13: Makes with vehicle count > 20,000
SELECT Make, COUNT(*) AS TotalVehicles 
FROM VehicleDetails 
GROUP BY Make 
HAVING COUNT(*) > 20000 
ORDER BY TotalVehicles DESC;

-- Problem 14: Makes starting with 'B'
SELECT DISTINCT Make FROM VehicleDetails WHERE Make LIKE 'B%';

-- Problem 15: Makes ending with 'W'
SELECT DISTINCT Make FROM VehicleDetails WHERE Make LIKE '%W';

-- Problem 16: Makes manufacturing DriveTypeName = 'FWD'
SELECT DISTINCT Make FROM VehicleDetails WHERE DriveTypeName = 'FWD';

-- Problem 17: Total count of Makes manufacturing 'FWD'
SELECT COUNT(DISTINCT Make) AS TotalFWDMakes FROM VehicleDetails WHERE DriveTypeName = 'FWD';

-- Problem 18: Total vehicles per DriveTypeName Per Make
SELECT Make, DriveTypeName, COUNT(*) AS TotalVehicles 
FROM VehicleDetails 
GROUP BY Make, DriveTypeName 
ORDER BY Make ASC, TotalVehicles DESC;

-- Problem 19: DriveTypeName Per Make where Total > 10,000
SELECT Make, DriveTypeName, COUNT(*) AS TotalVehicles 
FROM VehicleDetails 
GROUP BY Make, DriveTypeName 
HAVING COUNT(*) > 10000 
ORDER BY Make ASC, TotalVehicles DESC;

-- Problem 20: Vehicles where NumDoors is NULL
SELECT * FROM VehicleDetails WHERE NumDoors IS NULL;

-- Problem 21: Count of Vehicles where NumDoors is NULL
SELECT COUNT(*) AS VehiclesWithoutNumDoors FROM VehicleDetails WHERE NumDoors IS NULL;

-- Problem 22: Percentage of vehicles with no doors specified
SELECT CAST(COUNT(*) * 100.0 / (SELECT COUNT(*) FROM VehicleDetails) AS DECIMAL(5,2)) AS [PercentageNoDoors]
FROM VehicleDetails 
WHERE NumDoors IS NULL;

-- Problem 23: Vehicles with SubModelName = 'Elite'
SELECT MakeID, Make, SubModelName FROM VehicleDetails WHERE SubModelName = 'Elite';

-- Problem 24: Engine > 3.0 Liters and 2 Doors
SELECT * FROM VehicleDetails WHERE Engine_Liter_Display > 3.0 AND NumDoors = 2;

-- Problem 25: Engine contains 'OHV' and Cylinders = 4
SELECT Make, Vehicle_Display_Name, Engine FROM VehicleDetails WHERE Engine LIKE '%OHV%' AND Engine_Cylinders = 4;

-- Problem 26: Body = 'Sport Utility' and Year > 2020
SELECT * FROM VehicleDetails WHERE BodyName = 'Sport Utility' AND Year > 2020;

-- Problem 27: Body in ('Coupe', 'Hatchback', 'Sedan')
SELECT * FROM VehicleDetails WHERE BodyName IN ('Coupe', 'Hatchback', 'Sedan');

-- Problem 28: Body in ('Coupe', 'Hatchback', 'Sedan') and Year in (2008, 2020, 2021)
SELECT * FROM VehicleDetails 
WHERE BodyName IN ('Coupe', 'Hatchback', 'Sedan') AND Year IN (2008, 2020, 2021);

-- Problem 29: Check if any vehicle was made in 1950 (EXISTS)
SELECT CASE WHEN EXISTS(SELECT 1 FROM VehicleDetails WHERE Year = 1950) THEN 1 ELSE 0 END AS [Found];

-- Problem 30: Describe NumDoors in words with CASE
SELECT 
    Vehicle_Display_Name, 
    NumDoors,
    CASE 
        WHEN NumDoors = 2 THEN 'Two Doors'
        WHEN NumDoors = 3 THEN 'Three Doors'
        WHEN NumDoors = 4 THEN 'Four Doors'
        WHEN NumDoors = 5 THEN 'Five Doors'
        ELSE 'Not Set'
    END AS DoorDescription
FROM VehicleDetails;

-- Problem 31: Calculate car age
SELECT Vehicle_Display_Name, Year, (YEAR(GETDATE()) - Year) AS CarAge 
FROM VehicleDetails 
ORDER BY CarAge DESC;

-- Problem 32: Vehicles aged between 15 and 25 years old
SELECT Vehicle_Display_Name, Year, (YEAR(GETDATE()) - Year) AS CarAge 
FROM VehicleDetails 
WHERE (YEAR(GETDATE()) - Year) BETWEEN 15 AND 25;

-- Problem 33: Min, Max, and Avg Engine CC
SELECT MIN(Engine_CC) AS MinCC, MAX(Engine_CC) AS MaxCC, AVG(Engine_CC) AS AvgCC 
FROM VehicleDetails;

-- Problem 34: Vehicles with Minimum Engine CC
SELECT * FROM VehicleDetails WHERE Engine_CC = (SELECT MIN(Engine_CC) FROM VehicleDetails);

-- Problem 35: Vehicles with Maximum Engine CC
SELECT * FROM VehicleDetails WHERE Engine_CC = (SELECT MAX(Engine_CC) FROM VehicleDetails);

-- Problem 36: Vehicles with Engine_CC below average
SELECT * FROM VehicleDetails WHERE Engine_CC < (SELECT AVG(Engine_CC) FROM VehicleDetails WHERE Engine_CC IS NOT NULL);

-- Problem 37: Count of vehicles with Engine_CC above average
SELECT COUNT(*) AS AboveAvgEngineCount 
FROM VehicleDetails 
WHERE Engine_CC > (SELECT AVG(Engine_CC) FROM VehicleDetails WHERE Engine_CC IS NOT NULL);

-- Problem 38: Unique Engine_CC sorted descending
SELECT DISTINCT Engine_CC FROM VehicleDetails WHERE Engine_CC IS NOT NULL ORDER BY Engine_CC DESC;

-- Problem 39: Top 3 Maximum Engine CC
SELECT DISTINCT TOP 3 Engine_CC FROM VehicleDetails WHERE Engine_CC IS NOT NULL ORDER BY Engine_CC DESC;

-- Problem 40: Vehicles matching Top 3 Engine CC
SELECT * FROM VehicleDetails 
WHERE Engine_CC IN (SELECT DISTINCT TOP 3 Engine_CC FROM VehicleDetails WHERE Engine_CC IS NOT NULL ORDER BY Engine_CC DESC);

-- Problem 41: Makes manufacturing Top 3 Engine CC
SELECT DISTINCT Make FROM VehicleDetails 
WHERE Engine_CC IN (SELECT DISTINCT TOP 3 Engine_CC FROM VehicleDetails WHERE Engine_CC IS NOT NULL ORDER BY Engine_CC DESC);

-- Problem 42: Tax per Engine CC bracket
SELECT DISTINCT Engine_CC,
    CASE 
        WHEN Engine_CC < 1600 THEN 100
        WHEN Engine_CC BETWEEN 1600 AND 2500 THEN 250
        WHEN Engine_CC BETWEEN 2501 AND 3500 THEN 500
        ELSE 1000
    END AS AnnualTax
FROM VehicleDetails WHERE Engine_CC IS NOT NULL;

-- Problem 43: Total Doors Manufactured Per Make
SELECT Make, SUM(NumDoors) AS TotalDoors 
FROM VehicleDetails 
WHERE NumDoors IS NOT NULL 
GROUP BY Make 
ORDER BY TotalDoors DESC;

-- Problem 44: Total Doors Manufactured by 'Ford'
SELECT SUM(NumDoors) AS FordTotalDoors FROM VehicleDetails WHERE Make = 'Ford';

-- Problem 45: Number of Models Per Make
SELECT Make, COUNT(DISTINCT Model) AS NumberOfModels 
FROM VehicleDetails 
GROUP BY Make 
ORDER BY NumberOfModels DESC;

-- Problem 46: Top 3 Manufacturers with highest models
SELECT TOP 3 Make, COUNT(DISTINCT Model) AS NumberOfModels 
FROM VehicleDetails 
GROUP BY Make 
ORDER BY NumberOfModels DESC;

-- Problem 47: Highest number of models manufactured (Scalar)
SELECT MAX(NumberOfModels) AS MaxModelsCount 
FROM (SELECT COUNT(DISTINCT Model) AS NumberOfModels FROM VehicleDetails GROUP BY Make) T;

-- Problem 48: Make(s) with Highest number of models
SELECT Make, COUNT(DISTINCT Model) AS NumberOfModels 
FROM VehicleDetails 
GROUP BY Make 
HAVING COUNT(DISTINCT Model) = (
    SELECT MAX(NumberOfModels) FROM (SELECT COUNT(DISTINCT Model) AS NumberOfModels FROM VehicleDetails GROUP BY Make) T
);

-- Problem 49: Make(s) with Lowest number of models
SELECT Make, COUNT(DISTINCT Model) AS NumberOfModels 
FROM VehicleDetails 
GROUP BY Make 
HAVING COUNT(DISTINCT Model) = (
    SELECT MIN(NumberOfModels) FROM (SELECT COUNT(DISTINCT Model) AS NumberOfModels FROM VehicleDetails GROUP BY Make) T
);

-- Problem 50: Fuel Types in Random Order (NEWID())
SELECT FuelTypeName FROM FuelTypes ORDER BY NEWID();
GO
