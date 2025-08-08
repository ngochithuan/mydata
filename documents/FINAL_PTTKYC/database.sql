USE master
GO

CREATE DATABASE HotelManagement;
GO

USE HotelManagement;
GO

CREATE TABLE Users (
    userId INT IDENTITY(1,1) PRIMARY KEY,
    fullname NVARCHAR(100) NOT NULL,
    email VARCHAR(100),
    phone VARCHAR(20) NOT NULL,
    isStaff BIT NOT NULL,
    roleName NVARCHAR(50) CHECK (roleName IN ('normalStaff', 'cleaningStaff', 'guard', 'admin'))
);
GO

CREATE TABLE RoomType (
    roomTypeId INT IDENTITY(1,1) PRIMARY KEY,
    roomDesc NVARCHAR(MAX),
    roomFeatures NVARCHAR(MAX),
    roomAmenities NVARCHAR(MAX),
    roomImg VARCHAR(MAX),
    roomPrice FLOAT
);
GO

CREATE TABLE Rooms (
    roomId INT IDENTITY(1,1) PRIMARY KEY,
    roomTitle NVARCHAR(100),
    roomTypeId INT FOREIGN KEY REFERENCES RoomType(roomTypeId),
    roomDescription NVARCHAR(MAX),
    roomImage VARCHAR(MAX),
    roomStatus NVARCHAR(20) CHECK (roomStatus IN ('available', 'checkedin', 'pending'))
);
GO

CREATE TABLE Bookings (
    bookingId INT IDENTITY(1,1) PRIMARY KEY,
    userId INT NULL FOREIGN KEY REFERENCES Users(userId),
    fullname NVARCHAR(100),
    email VARCHAR(100),
    phone VARCHAR(20),
    checkInDate DATE NOT NULL,
    checkOutDate DATE NOT NULL,
    totalPrice FLOAT NOT NULL,
    paymentStatus NVARCHAR(50)
);
GO

CREATE TABLE BookingDetails (
    bookingDetailId INT IDENTITY(1,1) PRIMARY KEY,
    bookingId INT NOT NULL FOREIGN KEY REFERENCES Bookings(bookingId),
    roomId INT NOT NULL FOREIGN KEY REFERENCES Rooms(roomId)
);
GO

CREATE TABLE Reviews (
    reviewId INT IDENTITY(1,1) PRIMARY KEY,
    roomId INT NOT NULL FOREIGN KEY REFERENCES Rooms(roomId),
    userId INT NOT NULL FOREIGN KEY REFERENCES Users(userId),
    bookingId INT NOT NULL FOREIGN KEY REFERENCES Bookings(bookingId),
    reviewContent NVARCHAR(MAX),
    rating INT CHECK (rating BETWEEN 1 AND 5)
);
GO

CREATE TABLE RoomService (
    roomServiceId INT IDENTITY(1,1) PRIMARY KEY,
    roomId INT NOT NULL FOREIGN KEY REFERENCES Rooms(roomId),
    datetime DATETIME NOT NULL,
    isCleaningDone BIT DEFAULT 0
);
GO

CREATE TABLE ParkingService (
    parkingServiceId INT IDENTITY(1,1) PRIMARY KEY,
    bookingId INT NOT NULL FOREIGN KEY REFERENCES Bookings(bookingId),
    parkingPlateNo NVARCHAR(MAX) -- nhiều biển số, nên để text
);
