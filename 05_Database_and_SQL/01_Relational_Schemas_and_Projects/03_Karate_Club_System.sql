-- =====================================================================
-- Database Project 3: Karate Club Management System (Course 17)
-- Concepts: Belt Ranks, Subscriptions, Belt Tests, Instructors, Payments
-- =====================================================================

CREATE DATABASE KarateClubDB;
GO
USE KarateClubDB;
GO

-- 1. Persons Table
CREATE TABLE Persons (
    PersonID INT IDENTITY(1, 1) PRIMARY KEY,
    FullName NVARCHAR(100) NOT NULL,
    DateOfBirth DATE NOT NULL,
    Gender CHAR(1) NOT NULL CHECK (Gender IN ('M', 'F')),
    PhoneNumber NVARCHAR(20) NOT NULL,
    Address NVARCHAR(200) NULL
);

-- 2. Belt Ranks
CREATE TABLE BeltRanks (
    RankID INT IDENTITY(1, 1) PRIMARY KEY,
    RankName NVARCHAR(50) NOT NULL UNIQUE, -- 'White', 'Yellow', 'Green', 'Brown', 'Black'
    RankOrder TINYINT NOT NULL UNIQUE,
    TestFee DECIMAL(8, 2) NOT NULL CHECK (TestFee >= 0)
);

-- 3. Members
CREATE TABLE Members (
    MemberID INT IDENTITY(1, 1) PRIMARY KEY,
    PersonID INT NOT NULL UNIQUE,
    CurrentBeltRankID INT NOT NULL,
    EmergencyContactInfo NVARCHAR(200) NOT NULL,
    IsActive BIT NOT NULL DEFAULT 1,
    JoinDate DATE DEFAULT GETDATE(),

    CONSTRAINT FK_Members_Persons FOREIGN KEY (PersonID) REFERENCES Persons(PersonID) ON DELETE CASCADE,
    CONSTRAINT FK_Members_Ranks FOREIGN KEY (CurrentBeltRankID) REFERENCES BeltRanks(RankID)
);

-- 4. Instructors
CREATE TABLE Instructors (
    InstructorID INT IDENTITY(1, 1) PRIMARY KEY,
    PersonID INT NOT NULL UNIQUE,
    Qualification NVARCHAR(100) NOT NULL,

    CONSTRAINT FK_Instructors_Persons FOREIGN KEY (PersonID) REFERENCES Persons(PersonID) ON DELETE CASCADE
);

-- 5. Subscription Periods
CREATE TABLE Subscriptions (
    SubscriptionID INT IDENTITY(1, 1) PRIMARY KEY,
    MemberID INT NOT NULL,
    StartDate DATE NOT NULL,
    EndDate DATE NOT NULL,
    TotalFees DECIMAL(8, 2) NOT NULL CHECK (TotalFees >= 0),
    IsPaid BIT NOT NULL DEFAULT 0,

    CONSTRAINT FK_Subscriptions_Members FOREIGN KEY (MemberID) REFERENCES Members(MemberID),
    CONSTRAINT CHK_SubDates CHECK (EndDate >= StartDate)
);

-- 6. Belt Tests
CREATE TABLE BeltTests (
    TestID INT IDENTITY(1, 1) PRIMARY KEY,
    MemberID INT NOT NULL,
    TestedBeltRankID INT NOT NULL,
    InstructorID INT NOT NULL,
    TestDate DATE NOT NULL DEFAULT GETDATE(),
    IsPassed BIT NOT NULL,

    CONSTRAINT FK_Tests_Members FOREIGN KEY (MemberID) REFERENCES Members(MemberID),
    CONSTRAINT FK_Tests_Ranks FOREIGN KEY (TestedBeltRankID) REFERENCES BeltRanks(RankID),
    CONSTRAINT FK_Tests_Instructors FOREIGN KEY (InstructorID) REFERENCES Instructors(InstructorID)
);

-- 7. Payments
CREATE TABLE Payments (
    PaymentID INT IDENTITY(1, 1) PRIMARY KEY,
    MemberID INT NOT NULL,
    Amount DECIMAL(8, 2) NOT NULL CHECK (Amount > 0),
    PaymentDate DATETIME DEFAULT GETDATE(),
    PaymentReason NVARCHAR(50) NOT NULL CHECK (PaymentReason IN ('Subscription', 'Belt Test Fee', 'Uniform')),

    CONSTRAINT FK_Payments_Members FOREIGN KEY (MemberID) REFERENCES Members(MemberID)
);
GO
