USE master
GO
CREATE DATABASE ASSIGNMENT_QUAN_LY_THU_VIEN
GO
USE ASSIGNMENT_QUAN_LY_THU_VIEN
GO

CREATE TABLE TheLoai
(
  MaTheLoai VARCHAR(5) NOT NULL,
  TenTheLoai NVARCHAR(30) NOT NULL,
  CONSTRAINT PK_TheLoai PRIMARY KEY (MaTheLoai)
);

CREATE TABLE NhaXuatBan
(
  MaNXB VARCHAR(5) NOT NULL,
  TenNXB NVARCHAR(30) NOT NULL,
  DiaChi NVARCHAR(150) NOT NULL,
  CONSTRAINT PK_NhaXuatBan PRIMARY KEY (MaNXB)
);

CREATE TABLE DocGia
(
  MaDocGia VARCHAR(5) NOT NULL,
  Ho NVARCHAR(30) NOT NULL,
  Ten NVARCHAR(30) NOT NULL,
  DiaChi NVARCHAR(150) NOT NULL,
  CONSTRAINT PK_DocGia PRIMARY KEY (MaDocGia)
);

CREATE TABLE ThanNhan
(
  Ho NVARCHAR(30) NOT NULL,
  Ten NVARCHAR(30) NOT NULL,
  SDT VARCHAR(15) NOT NULL,
  MaDocGia VARCHAR(5) NOT NULL,
  CONSTRAINT PK_ThanNhan PRIMARY KEY (MaDocGia),
  CONSTRAINT FK_ThanNhan_DocGia FOREIGN KEY (MaDocGia) REFERENCES DocGia(MaDocGia)
);

CREATE TABLE TaiLieu
(
  MaTaiLieu VARCHAR(5) NOT NULL,
  TenTaiLieu NVARCHAR(30) NOT NULL,
  MaNXB VARCHAR(5) NOT NULL,
  CONSTRAINT PK_TaiLieu PRIMARY KEY (MaTaiLieu),
  CONSTRAINT FK_TaiLieu_NhaXuatBan FOREIGN KEY (MaNXB) REFERENCES NhaXuatBan(MaNXB)
);

CREATE TABLE Sach
(
  MaTaiLieu VARCHAR(5) NOT NULL,
  TenTaiLieu NVARCHAR(30) NOT NULL,
  MaTheLoai VARCHAR(5) NOT NULL,
  TacGia NVARCHAR(30) NOT NULL,
  CONSTRAINT PK_Sach PRIMARY KEY (MaTaiLieu),
  CONSTRAINT FK_Sach_TaiLieu FOREIGN KEY (MaTaiLieu) REFERENCES TaiLieu(MaTaiLieu),
  CONSTRAINT FK_Sach_TheLoai FOREIGN KEY (MaTheLoai) REFERENCES TheLoai(MaTheLoai)
);

CREATE TABLE Bao
(
  MaTaiLieu VARCHAR(5) NOT NULL,
  TenTaiLieu NVARCHAR(30) NOT NULL,
  NgayXuatBan SMALLDATETIME NOT NULL,
  CONSTRAINT PK_Bao PRIMARY KEY (MaTaiLieu),
  CONSTRAINT FK_Bao_TaiLieu FOREIGN KEY (MaTaiLieu) REFERENCES TaiLieu(MaTaiLieu)
);

CREATE TABLE PhieuMuon
(
  MaPhieuMuon VARCHAR(5) NOT NULL,
  MaDocGia VARCHAR(5) NOT NULL,
  CONSTRAINT PK_PhieuMuon PRIMARY KEY (MaPhieuMuon),
  CONSTRAINT FK_PhieuMuon_DocGia FOREIGN KEY (MaDocGia) REFERENCES DocGia(MaDocGia)
);

CREATE TABLE ChiTietPhieuMuon
(
  MaPhieuMuon VARCHAR(5) NOT NULL,
  MaTaiLieu VARCHAR(5) NOT NULL,
  CONSTRAINT PK_CTPM PRIMARY KEY (MaPhieuMuon, MaTaiLieu),
  CONSTRAINT FK_CTPM_PhieuMuon FOREIGN KEY (MaPhieuMuon) REFERENCES PhieuMuon(MaPhieuMuon),
  CONSTRAINT FK_CTPM_TaiLieu FOREIGN KEY (MaTaiLieu) REFERENCES TaiLieu(MaTaiLieu)
);

GO

CREATE PROC INSERT_Sach @TS NVARCHAR(30), @MTL VARCHAR(5), @TG NVARCHAR(30)
AS
BEGIN
	IF NOT EXISTS (SELECT * FROM TheLoai WHERE MaTheLoai = @MTL)
	BEGIN
		PRINT 'Khong co the loai nay!'
		RETURN
	END


	DECLARE @MaSachMax VARCHAR(5)
	SET @MaSachMax =
	(
	SELECT TOP 1 MaTaiLieu FROM Sach
	WHERE MaTaiLieu LIKE 'S____'
	ORDER BY MaTaiLieu DESC
	)

	DECLARE @MaxNum INT
	SET @MaSachMax = right(@MaSachMax, len(@MaSachMax)-1)
	SET @MaxNum = CONVERT(INT, @MaSachMax)
	DECLARE @str VARCHAR(5)
	SET @MaxNum = @MaxNum+1
	DECLARE @NumChar VARCHAR(5) = CONVERT(CHAR, @MaxNum)

	IF @NumChar like '_'
		SET @NumChar = '000' + @NumChar
	else if @NumChar like '__'
		SET @NumChar = '00' + @NumChar
	else if @NumChar like '___'
		SET @NumChar = '0' + @NumChar

	SET @str = 'S' + @NumChar

	INSERT INTO Sach
	VALUES(@str, @TS, @MTL, @TG)	
END

GO

CREATE PROC INSERT_Bao @TB NVARCHAR(30)
AS
BEGIN
	DECLARE @MaSachMax VARCHAR(5)
	SET @MaSachMax =
	(
	SELECT TOP 1 MaTaiLieu FROM Bao
	WHERE MaTaiLieu LIKE 'B____'
	ORDER BY MaTaiLieu DESC
	)

	DECLARE @MaxNum INT
	SET @MaSachMax = right(@MaSachMax, len(@MaSachMax)-1)
	SET @MaxNum = CONVERT(INT, @MaSachMax)
	DECLARE @str VARCHAR(5)
	SET @MaxNum = @MaxNum+1
	DECLARE @NumChar VARCHAR(5) = CONVERT(CHAR, @MaxNum)

	IF @NumChar like '_'
		SET @NumChar = '000' + @NumChar
	else if @NumChar like '__'
		SET @NumChar = '00' + @NumChar
	else if @NumChar like '___'
		SET @NumChar = '0' + @NumChar

	SET @str = 'B' + @NumChar

	INSERT INTO Bao
	VALUES(@str, @TB, GETDATE())	
END

GO

CREATE TRIGGER TriggerBao ON Bao
FOR INSERT, UPDATE
AS
BEGIN
	IF NOT EXISTS (SELECT inserted.MaTaiLieu FROM inserted, TaiLieu WHERE inserted.MaTaiLieu = TaiLieu.MaTaiLieu)
		BEGIN
			PRINT 'Khong ton tai ma tai lieu nay'
			ROLLBACK
		END
	IF EXISTS (SELECT inserted.NgayXuatBan FROM inserted WHERE NgayXuatBan > GETDATE())
		BEGIN
			PRINT 'Ngay xuat ban khong the lon hon ngay hien tai'
			ROLLBACK
		END
	IF EXISTS (SELECT inserted.NgayXuatBan FROM inserted WHERE LEN(TenTaiLieu) > 30 OR LEN(MaTaiLieu) > 5)
		BEGIN
			PRINT 'Ma tai lieu hoac Ten du lieu co do dai qua lon'
			ROLLBACK
		END
END

/*
use master 
go
drop database ASSIGNMENT_QUAN_LY_THU_VIEN
*/