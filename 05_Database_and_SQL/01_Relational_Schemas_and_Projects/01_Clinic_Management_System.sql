-- =====================================================================
-- Database Project 1: Simple Clinic Management System (Course 17)
-- Concepts: DDL, Primary Keys, Foreign Keys, Referential Integrity, Indexes
-- =====================================================================

CREATE DATABASE ClinicDB;
GO
USE ClinicDB;
GO

-- 1. Persons Table (Base table for Patient & Doctor contact info)
CREATE TABLE Persons (
    PersonID INT IDENTITY(1, 1) PRIMARY KEY,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL,
    DateOfBirth DATE NOT NULL,
    Gender CHAR(1) NOT NULL CHECK (Gender IN ('M', 'F')),
    PhoneNumber NVARCHAR(20) NOT NULL,
    Email NVARCHAR(100) NULL,
    Address NVARCHAR(250) NULL
);

-- 2. Patients Table
CREATE TABLE Patients (
    PatientID INT IDENTITY(1, 1) PRIMARY KEY,
    PersonID INT NOT NULL UNIQUE,
    EmergencyContactName NVARCHAR(100) NOT NULL,
    EmergencyContactPhone NVARCHAR(20) NOT NULL,
    CreatedAt DATETIME DEFAULT GETDATE(),

    CONSTRAINT FK_Patients_Persons FOREIGN KEY (PersonID) 
        REFERENCES Persons(PersonID) ON DELETE CASCADE
);

-- 3. Specializations Table
CREATE TABLE Specializations (
    SpecializationID INT IDENTITY(1, 1) PRIMARY KEY,
    SpecializationName NVARCHAR(100) NOT NULL UNIQUE
);

-- 4. Doctors Table
CREATE TABLE Doctors (
    DoctorID INT IDENTITY(1, 1) PRIMARY KEY,
    PersonID INT NOT NULL UNIQUE,
    SpecializationID INT NOT NULL,
    ConsultationFee DECIMAL(8, 2) NOT NULL CHECK (ConsultationFee >= 0),

    CONSTRAINT FK_Doctors_Persons FOREIGN KEY (PersonID) 
        REFERENCES Persons(PersonID) ON DELETE CASCADE,
    CONSTRAINT FK_Doctors_Specializations FOREIGN KEY (SpecializationID) 
        REFERENCES Specializations(SpecializationID)
);

-- 5. Appointments Table
CREATE TABLE Appointments (
    AppointmentID INT IDENTITY(1, 1) PRIMARY KEY,
    PatientID INT NOT NULL,
    DoctorID INT NOT NULL,
    AppointmentDateTime DATETIME NOT NULL,
    Status NVARCHAR(20) NOT NULL DEFAULT 'Scheduled' 
        CHECK (Status IN ('Scheduled', 'Completed', 'Cancelled', 'NoShow')),
    Notes NVARCHAR(MAX) NULL,

    CONSTRAINT FK_Appointments_Patients FOREIGN KEY (PatientID) REFERENCES Patients(PatientID),
    CONSTRAINT FK_Appointments_Doctors FOREIGN KEY (DoctorID) REFERENCES Doctors(DoctorID)
);

-- 6. Medical Records Table
CREATE TABLE MedicalRecords (
    RecordID INT IDENTITY(1, 1) PRIMARY KEY,
    AppointmentID INT NOT NULL UNIQUE,
    Diagnosis NVARCHAR(MAX) NOT NULL,
    VisitDescription NVARCHAR(MAX) NULL,
    RecordedAt DATETIME DEFAULT GETDATE(),

    CONSTRAINT FK_MedicalRecords_Appointments FOREIGN KEY (AppointmentID) 
        REFERENCES Appointments(AppointmentID)
);

-- 7. Prescriptions Table
CREATE TABLE Prescriptions (
    PrescriptionID INT IDENTITY(1, 1) PRIMARY KEY,
    RecordID INT NOT NULL,
    MedicationName NVARCHAR(100) NOT NULL,
    Dosage NVARCHAR(50) NOT NULL,
    Frequency NVARCHAR(50) NOT NULL,
    StartDate DATE NOT NULL,
    EndDate DATE NOT NULL,
    SpecialInstructions NVARCHAR(500) NULL,

    CONSTRAINT FK_Prescriptions_MedicalRecords FOREIGN KEY (RecordID) 
        REFERENCES MedicalRecords(RecordID) ON DELETE CASCADE,
    CONSTRAINT CHK_PrescriptionDates CHECK (EndDate >= StartDate)
);

-- 8. Payments Table
CREATE TABLE Payments (
    PaymentID INT IDENTITY(1, 1) PRIMARY KEY,
    AppointmentID INT NOT NULL UNIQUE,
    AmountPaid DECIMAL(8, 2) NOT NULL CHECK (AmountPaid >= 0),
    PaymentDate DATETIME DEFAULT GETDATE(),
    PaymentMethod NVARCHAR(30) NOT NULL CHECK (PaymentMethod IN ('Cash', 'Credit Card', 'Insurance', 'Bank Transfer')),

    CONSTRAINT FK_Payments_Appointments FOREIGN KEY (AppointmentID) 
        REFERENCES Appointments(AppointmentID)
);

-- Indexes for Query Performance
CREATE NONCLUSTERED INDEX IX_Appointments_Patient ON Appointments(PatientID);
CREATE NONCLUSTERED INDEX IX_Appointments_Doctor ON Appointments(DoctorID);
CREATE NONCLUSTERED INDEX IX_Appointments_Date ON Appointments(AppointmentDateTime);
GO
