CREATE DATABASE 'localhost:RS' DEFAULT CHARACTER SET ISO8859_1;

DECLARE EXTERNAL FUNCTION MOD
Integer, Integer
RETURNS Double precision BY VALUE 
ENTRY_POINT 'IB_UDF_mod'
MODULE_NAME 'ib_udf';

/****************** GENERATORS ********************/

CREATE GENERATOR GENAREAS;
CREATE GENERATOR GENMODELOS;
CREATE GENERATOR GENRESERVAS;
CREATE GENERATOR GENUSUARIOS;
CREATE GENERATOR SEQRESERVAS;
/******************** DOMAINS *********************/

/******************* PROCEDURES ******************/

SET TERM ^ ;
CREATE PROCEDURE CHECK_USUARIO_SALA (
    USUARIOID Integer,
    SALAID Integer )
AS
BEGIN EXIT; END^
SET TERM ; ^

SET TERM ^ ;
CREATE PROCEDURE CREATE_RESERVA_MENSAL (
    RESERVAID Integer,
    SALAID Integer,
    USUARIOID Integer,
    ASSUNTO Varchar(255),
    DEPTO Varchar(80),
    NOTAS Blob sub_type 1,
    DATAIN Date,
    DATAFIM Date,
    HORAIN Time,
    HORAFIM Time,
    DIA_S Integer,
    ORDEM Integer )
RETURNS (
    OUT_RESERVAID Integer,
    SEQ Integer )
AS
BEGIN EXIT; END^
SET TERM ; ^

SET TERM ^ ;
CREATE PROCEDURE CREATE_RESERVA_SEMANAL (
    RESERVAID Integer,
    SALAID Integer,
    USUARIOID Integer,
    ASSUNTO Varchar(255),
    DEPTO Varchar(80),
    NOTAS Blob sub_type 1,
    DATAIN Date,
    DATAFIM Date,
    HORAIN Time,
    HORAFIM Time,
    SEG Smallint,
    TER Smallint,
    QUA Smallint,
    QUI Smallint,
    SEX Smallint,
    SAB Smallint,
    DOM Smallint,
    REVESA Smallint )
RETURNS (
    OUT_RESERVAID Integer,
    SEQ Integer )
AS
BEGIN EXIT; END^
SET TERM ; ^

SET TERM ^ ;
CREATE PROCEDURE CREATE_RESERVA_SIMPLES (
    RESERVAID Integer,
    SALAID Integer,
    USUARIOID Integer,
    ASSUNTO Varchar(255),
    DEPTO Varchar(80),
    NOTAS Blob sub_type 1,
    DATA Date,
    HORAIN Time,
    HORAFIM Time )
RETURNS (
    OUT_RESERVAID Integer,
    SEQ Integer )
AS
BEGIN EXIT; END^
SET TERM ; ^

SET TERM ^ ;
CREATE PROCEDURE GET_RESERVAS_SEMANA (
    START Date,
    ENDDT Date,
    AREAID Integer )
RETURNS (
    RESERVAID Integer,
    SALAID Integer,
    DATA Date,
    HORAIN Time,
    HORAFIM Time,
    USUARIOID Integer,
    USUARIO_NOME Varchar(255),
    ASSUNTO Varchar(255),
    DEPTO Varchar(80),
    NOTAS Blob sub_type 1,
    SCHEMEID Integer,
    SEQ Integer,
    TIPO Char(1),
    DATAIN Date,
    DATAFIM Date )
AS
BEGIN EXIT; END^
SET TERM ; ^

SET TERM ^ ;
CREATE PROCEDURE GET_SEMANAL_DIAS (
    RESERVAID Integer,
    DATAIN Date,
    DATAFIM Date )
RETURNS (
    DIAS Date )
AS
BEGIN EXIT; END^
SET TERM ; ^

/******************** TABLES **********************/

CREATE TABLE AREAS
(
  AREAID Integer NOT NULL,
  AREA Varchar(80) NOT NULL COLLATE ISO8859_1,
  CONSTRAINT PKAREAS PRIMARY KEY (AREAID)
);
CREATE TABLE COLOR_SCHEME
(
  SCHEMEID Integer NOT NULL,
  BACKGROUND Integer,
  FONT Integer,
  BORDER Integer,
  CONSTRAINT PKCOLOR_SCHEME PRIMARY KEY (SCHEMEID)
);
CREATE TABLE DEL$RESERVAS
(
  RESERVAID Integer,
  SEQ Integer NOT NULL,
  DATA_DEL Date DEFAULT CURRENT_DATE
);
CREATE TABLE MODELOS
(
  MODELOID Integer NOT NULL,
  NOME Varchar(60) NOT NULL COLLATE PT_PT,
  BODY Blob sub_type 1 COLLATE ISO8859_1,
  ITEM Blob sub_type 1 COLLATE ISO8859_1,
  FUNDO Varchar(60) COLLATE ISO8859_1,
  FUNDOALT Varchar(60) COLLATE ISO8859_1,
  CONSTRAINT PKMODELOS PRIMARY KEY (MODELOID)
);
CREATE TABLE RESERVAS
(
  RESERVAID Integer NOT NULL,
  TIPO Char(1) NOT NULL COLLATE ISO8859_1,
  SALAID Integer NOT NULL,
  USUARIOID Integer NOT NULL,
  ASSUNTO Varchar(255) NOT NULL COLLATE ISO8859_1,
  DEPTO Varchar(80) COLLATE ISO8859_1,
  NOTAS Blob sub_type 1 COLLATE ISO8859_1,
  SEQ Integer,
  CONSTRAINT PKRESERVAS PRIMARY KEY (RESERVAID)
);
CREATE TABLE RESERVA_MENSAL
(
  RESERVAID Integer NOT NULL,
  DATAIN Date NOT NULL,
  DATAFIM Date NOT NULL,
  HORAIN Time NOT NULL,
  HORAFIM Time NOT NULL,
  DIA_S Integer NOT NULL,
  ORDEM Integer NOT NULL
);
CREATE TABLE RESERVA_SEMANAL
(
  RESERVAID Integer NOT NULL,
  DATAIN Date NOT NULL,
  DATAFIM Date NOT NULL,
  HORAIN Time NOT NULL,
  HORAFIM Time NOT NULL,
  SEG Smallint DEFAULT 0 NOT NULL,
  TER Smallint DEFAULT 0 NOT NULL,
  QUA Smallint DEFAULT 0 NOT NULL,
  QUI Smallint DEFAULT 0 NOT NULL,
  SEX Smallint DEFAULT 0 NOT NULL,
  SAB Smallint DEFAULT 0 NOT NULL,
  DOM Smallint DEFAULT 0 NOT NULL,
  REVESA Smallint DEFAULT 0 NOT NULL
);
CREATE TABLE RESERVA_SIMPLES
(
  RESERVAID Integer NOT NULL,
  DATA Date NOT NULL,
  HORAIN Time NOT NULL,
  HORAFIM Time NOT NULL
);
CREATE TABLE SALAS
(
  SALAID Integer NOT NULL,
  ANDAR Integer,
  NOME Varchar(80) COLLATE ISO8859_1,
  CONSTRAINT PKSALAS PRIMARY KEY (SALAID)
);
CREATE TABLE SALAS_AREAS
(
  SALAID Integer NOT NULL,
  AREAID Integer NOT NULL,
  CONSTRAINT PKSALAS_AREAS PRIMARY KEY (SALAID,AREAID)
);
CREATE TABLE USUARIOS
(
  USUARIOID Integer NOT NULL,
  LOGIN Varchar(80) NOT NULL COLLATE PT_PT,
  NOME Varchar(300) NOT NULL COLLATE ISO8859_1,
  STYLE Varchar(120) COLLATE ISO8859_1,
  SCHEMEID Integer,
  NIVEL Integer,
  CONSTRAINT PKUSUARIOS PRIMARY KEY (USUARIOID)
);
CREATE TABLE USUARIOS_AREAS
(
  USUARIOID Integer NOT NULL,
  AREAID Integer NOT NULL,
  CONSTRAINT PKUSUARIOS_AREAS PRIMARY KEY (USUARIOID,AREAID)
);
/********************* VIEWS **********************/

/******************* EXCEPTIONS *******************/

CREATE EXCEPTION EXPRESERVAHORA
'JA EXISTE UMA RESERVA NESSE HORARIO';
CREATE EXCEPTION EXPUSUARIOAREA
'Este usuario nao pode fazer uma reserva nesta sala/area';
/******************** TRIGGERS ********************/

SET TERM ^ ;
CREATE TRIGGER TRIG_EVT_RESERVA FOR RESERVAS ACTIVE
AFTER INSERT OR UPDATE OR DELETE POSITION 0
AS 
BEGIN 
	IF (INSERTING) THEN
	BEGIN
		POST_EVENT 'reserva_ins';
	END
	ELSE IF (UPDATING) THEN
	BEGIN
		POST_EVENT 'reserva_upd';
	END
	ELSE IF (DELETING) THEN
	BEGIN
		POST_EVENT 'reserva_del';
	END
END^
SET TERM ; ^
SET TERM ^ ;
CREATE TRIGGER TRIG_UPD_RESERVA FOR RESERVAS ACTIVE
BEFORE INSERT OR UPDATE OR DELETE POSITION 0
AS 
BEGIN 
	IF (UPDATING OR INSERTING) THEN
		NEW.SEQ = GEN_ID(SEQRESERVAS, 1);
	ELSE
	BEGIN
		DELETE FROM
			DEL$RESERVAS D
		WHERE 
			D.DATA_DEL < CURRENT_DATE;
	
		INSERT INTO DEL$RESERVAS ("RESERVAID", "SEQ")
		VALUES (OLD.RESERVAID, GEN_ID(SEQRESERVAS, 1));
	END
END^
SET TERM ; ^

SET TERM ^ ;
ALTER PROCEDURE CHECK_USUARIO_SALA (
    USUARIOID Integer,
    SALAID Integer )
AS
DECLARE VARIABLE NIVEL INTEGER;
    DECLARE VARIABLE I INTEGER;
BEGIN
    SELECT 
        NIVEL
    FROM
        USUARIOS 
    WHERE
        USUARIOID = :USUARIOID
    INTO 
        :NIVEL;

    IF (:NIVEL IS NULL OR :NIVEL < 1) THEN
        EXCEPTION EXPUSUARIOAREA;
    ELSE IF (:NIVEL < 3) THEN
    BEGIN
        SELECT FIRST 1
            1
        FROM    
            USUARIOS_AREAS UA 
                JOIN SALAS_AREAS SA ON
                    UA.AREAID = SA.AREAID
        WHERE
            UA.USUARIOID = :USUARIOID AND
            SA.SALAID = :SALAID
        INTO
            :I;
    
        IF (I IS NULL) THEN
            EXCEPTION EXPUSUARIOAREA;
    END
END^
SET TERM ; ^

GRANT EXECUTE
 ON PROCEDURE CHECK_USUARIO_SALA TO  RS;

GRANT EXECUTE
 ON PROCEDURE CHECK_USUARIO_SALA TO  SYSDBA;


SET TERM ^ ;
ALTER PROCEDURE CREATE_RESERVA_MENSAL (
    RESERVAID Integer,
    SALAID Integer,
    USUARIOID Integer,
    ASSUNTO Varchar(255),
    DEPTO Varchar(80),
    NOTAS Blob sub_type 1,
    DATAIN Date,
    DATAFIM Date,
    HORAIN Time,
    HORAFIM Time,
    DIA_S Integer,
    ORDEM Integer )
RETURNS (
    OUT_RESERVAID Integer,
    SEQ Integer )
AS
BEGIN
END^
SET TERM ; ^

GRANT EXECUTE
 ON PROCEDURE CREATE_RESERVA_MENSAL TO  RS;

GRANT EXECUTE
 ON PROCEDURE CREATE_RESERVA_MENSAL TO  SYSDBA;


SET TERM ^ ;
ALTER PROCEDURE CREATE_RESERVA_SEMANAL (
    RESERVAID Integer,
    SALAID Integer,
    USUARIOID Integer,
    ASSUNTO Varchar(255),
    DEPTO Varchar(80),
    NOTAS Blob sub_type 1,
    DATAIN Date,
    DATAFIM Date,
    HORAIN Time,
    HORAFIM Time,
    SEG Smallint,
    TER Smallint,
    QUA Smallint,
    QUI Smallint,
    SEX Smallint,
    SAB Smallint,
    DOM Smallint,
    REVESA Smallint )
RETURNS (
    OUT_RESERVAID Integer,
    SEQ Integer )
AS
DECLARE VARIABLE I INT;
    DECLARE VARIABLE ID INT;
    DECLARE VARIABLE OLD_TIPO CHAR;
BEGIN
    EXECUTE PROCEDURE CHECK_USUARIO_SALA(USUARIOID, SALAID);

    FOR
        SELECT
            EXTRACT(WEEKDAY FROM RS.DATA)
        FROM
            RESERVAS R JOIN RESERVA_SIMPLES RS ON
                R.RESERVAID = RS.RESERVAID
        WHERE
            (:SALAID = R.SALAID) AND 
            ((RS.DATA>= :DATAIN) AND (:DATAFIM IS NULL OR RS.DATA <= :DATAFIM)) AND
                (((:HORAIN >= RS.HORAIN) AND (:HORAIN < RS.HORAFIM))
                OR
                ((:HORAFIM > RS.HORAIN) AND (:HORAFIM <= RS.HORAFIM))
                OR
                ((:HORAIN <= RS.HORAIN) AND (:HORAFIM > RS.HORAIN)))
        INTO
            :I
    DO
    BEGIN
        IF (((NOT :SEG IS NULL) AND :SEG != 0 AND :I = 1) OR
            ((NOT :TER IS NULL) AND :TER != 0 AND :I = 2) OR
            ((NOT :QUA IS NULL) AND :QUA != 0 AND :I = 3) OR
            ((NOT :QUI IS NULL) AND :QUI != 0 AND :I = 4) OR
            ((NOT :SEX IS NULL) AND :SEX != 0 AND :I = 5) OR
            ((NOT :SAB IS NULL) AND :SAB != 0 AND :I = 6) OR
            ((NOT :DOM IS NULL) AND :DOM != 0 AND :I = 0)) THEN
            EXCEPTION EXPRESERVAHORA;
    END

    SELECT FIRST 1
        RS.RESERVAID
    FROM
        RESERVAS R JOIN RESERVA_SEMANAL RS ON
            R.RESERVAID = RS.RESERVAID
    WHERE
        (R.RESERVAID != :RESERVAID)
        AND (:SALAID = R.SALAID)
        AND
            (
            ((:DATAIN >= RS.DATAIN) AND (:DATAIN < RS.DATAFIM))
            OR
            ((:DATAFIM > RS.DATAIN) AND (:DATAFIM <= RS.DATAFIM))
            OR
            ((:DATAIN <= RS.DATAIN) AND (:DATAFIM > RS.DATAIN))
            )
        AND
            (
            ((:HORAIN >= RS.HORAIN) AND (:HORAIN < RS.HORAFIM))
            OR
            ((:HORAFIM > RS.HORAIN) AND (:HORAFIM <= RS.HORAFIM))
            OR
            ((:HORAIN <= RS.HORAIN) AND (:HORAFIM > RS.HORAIN))
            )
        AND
            (
            ((NOT :SEG IS NULL) AND :SEG != 0 AND RS.SEG = 1) OR
            ((NOT :TER IS NULL) AND :TER != 0 AND RS.TER = 1) OR
            ((NOT :QUA IS NULL) AND :QUA != 0 AND RS.QUA = 1) OR
            ((NOT :QUI IS NULL) AND :QUI != 0 AND RS.QUI = 1) OR
            ((NOT :SEX IS NULL) AND :SEX != 0 AND RS.SEX = 1) OR
            ((NOT :SAB IS NULL) AND :SAB != 0 AND RS.SAB = 1) OR
            ((NOT :DOM IS NULL) AND :DOM != 0 AND RS.DOM = 1)
            )
        AND
            (
            (:REVESA IS NULL) OR (:REVESA = 0) OR
            (RS.REVESA IS NULL) OR (RS.REVESA = 0) OR
            ((:REVESA = 1) AND (RS.REVESA = 1) AND
             (MOD((:DATAIN - RS.DATAIN - EXTRACT(WEEKDAY FROM RS.DATAIN)) / 7, 2) = 0)
             )
            )
    INTO
        I;

    IF (NOT (I IS NULL)) THEN
        EXCEPTION EXPRESERVAHORA;

    SEQ = GEN_ID(SEQRESERVAS, 1);

    IF ((:RESERVAID IS NULL) OR (:RESERVAID < 0)) THEN  
    BEGIN
        OUT_RESERVAID = GEN_ID(GENRESERVAS, 1);

        INSERT INTO
            RESERVAS (RESERVAID, SALAID, USUARIOID, ASSUNTO, DEPTO, NOTAS, SEQ, TIPO)
        VALUES
            (:OUT_RESERVAID, :SALAID, :USUARIOID, :ASSUNTO, :DEPTO, :NOTAS, :SEQ, 'W');

        INSERT INTO
            RESERVA_SEMANAL (RESERVAID, DATAIN, DATAFIM, HORAIN, HORAFIM, SEG, TER, 
                                            QUA, QUI, SEX, SAB, DOM, REVESA)
        VALUES (:OUT_RESERVAID, :DATAIN, :DATAFIM, :HORAIN, :HORAFIM, :SEG, :TER, :QUA, 
                        :QUI, :SEX, :SAB, :DOM, :REVESA);
    END
    ELSE
    BEGIN
        OUT_RESERVAID = :RESERVAID;

        SELECT
            TIPO
        FROM
            RESERVAS
        WHERE
            RESERVAID = :RESERVAID
        INTO
            :OLD_TIPO;

        UPDATE
            RESERVAS
        SET
            SALAID = :SALAID, 
            USUARIOID = :USUARIOID, 
            ASSUNTO = :ASSUNTO, 
            DEPTO = :DEPTO, 
            NOTAS = :NOTAS, 
            SEQ = :SEQ
        WHERE
            RESERVAID = :RESERVAID;

        IF (OLD_TIPO = 'M') THEN
            DELETE FROM RESERVA_MENSAL WHERE RESERVAID = :RESERVAID;
        ELSE IF (OLD_TIPO = 'S') THEN
            DELETE FROM RESERVA_SIMPLES WHERE RESERVAID = :RESERVAID;

        IF (OLD_TIPO = 'W') THEN
            UPDATE
                RESERVA_SEMANAL
            SET
                DATAIN = :DATAIN,
                DATAFIM = :DATAFIM,
                HORAIN = :HORAIN,
                HORAFIM = HORAFIM,
                SEG = :SEG,
                TER = :TER,
                QUA = :QUA,
                QUI = :QUI,
                SEX = :SEX,
                SAB = :SAB,
                DOM = :DOM,
                REVESA = :REVESA
            WHERE
                RESERVAID = :OUT_RESERVAID;
        ELSE
            INSERT INTO
                RESERVA_SEMANAL (RESERVAID, DATAIN, DATAFIM, HORAIN, HORAFIM, SEG, TER,
                                                QUA, QUI, SEX, SAB, DOM, REVESA)
            VALUES (:OUT_RESERVAID, :DATAIN, :DATAFIM, :HORAIN, :HORAFIM, :SEG, :TER, :QUA,
                            :QUI, :SEX, :SAB, :DOM, :REVESA);
    END

    SUSPEND;
END^
SET TERM ; ^

GRANT EXECUTE
 ON PROCEDURE CREATE_RESERVA_SEMANAL TO  RS;

GRANT EXECUTE
 ON PROCEDURE CREATE_RESERVA_SEMANAL TO  SYSDBA;


SET TERM ^ ;
ALTER PROCEDURE CREATE_RESERVA_SIMPLES (
    RESERVAID Integer,
    SALAID Integer,
    USUARIOID Integer,
    ASSUNTO Varchar(255),
    DEPTO Varchar(80),
    NOTAS Blob sub_type 1,
    DATA Date,
    HORAIN Time,
    HORAFIM Time )
RETURNS (
    OUT_RESERVAID Integer,
    SEQ Integer )
AS
DECLARE VARIABLE I INT;
    DECLARE VARIABLE ID INT;
    DECLARE VARIABLE OLD_TIPO CHAR;
BEGIN
    EXECUTE PROCEDURE CHECK_USUARIO_SALA(USUARIOID, SALAID);

    SELECT FIRST 1
        R.RESERVAID
    FROM
        GET_RESERVAS_SEMANA(:DATA, :DATA, (SELECT AREAID FROM SALAS_AREAS WHERE SALAID = :SALAID)) R
    WHERE
        (:SALAID = R.SALAID) AND
            (((:HORAIN >= R.HORAIN) AND (:HORAIN < R.HORAFIM))
            OR
            ((:HORAFIM > R.HORAIN) AND (:HORAFIM <= R.HORAFIM))
            OR
            ((:HORAIN <= R.HORAIN) AND (:HORAFIM > R.HORAIN)))
    INTO
        I;

    IF (NOT (I IS NULL OR I = :RESERVAID)) THEN
        EXCEPTION EXPRESERVAHORA;

    SEQ = GEN_ID(SEQRESERVAS, 1);

    IF ((:RESERVAID IS NULL) OR (:RESERVAID < 0)) THEN
    BEGIN
        OUT_RESERVAID = GEN_ID(GENRESERVAS, 1);

        INSERT INTO
            RESERVAS (RESERVAID, SALAID, USUARIOID, ASSUNTO, DEPTO, NOTAS, SEQ, TIPO)
        VALUES
            (:OUT_RESERVAID, :SALAID, :USUARIOID, :ASSUNTO, :DEPTO, :NOTAS, :SEQ, 'S');

        INSERT INTO
            RESERVA_SIMPLES (RESERVAID, DATA, HORAIN, HORAFIM)
        VALUES
            (:OUT_RESERVAID, :DATA, :HORAIN, :HORAFIM);
    END
    ELSE
    BEGIN
        OUT_RESERVAID = :RESERVAID;

        SELECT
            TIPO
        FROM
            RESERVAS
        WHERE
            RESERVAID = :RESERVAID
        INTO
            :OLD_TIPO;

        UPDATE
            RESERVAS
        SET
            SALAID = :SALAID,
            USUARIOID = :USUARIOID,
            ASSUNTO = :ASSUNTO,
            DEPTO = :DEPTO,
            NOTAS = :NOTAS,
            SEQ = :SEQ
        WHERE
            RESERVAID = :RESERVAID;

        IF (OLD_TIPO = 'M') THEN
            DELETE FROM RESERVA_MENSAL WHERE RESERVAID = :RESERVAID;
        ELSE IF (OLD_TIPO = 'W') THEN
            DELETE FROM RESERVA_SEMANAL WHERE RESERVAID = :RESERVAID;

        IF (OLD_TIPO = 'S') THEN
            UPDATE
                RESERVA_SIMPLES
            SET
                DATA = :DATA,
                HORAIN = :HORAIN,
                HORAFIM = :HORAFIM
            WHERE
                RESERVAID = :RESERVAID;
        ELSE
            INSERT INTO
                RESERVA_SIMPLES (DATA, HORAIN, HORAFIM)
            VALUES
                (:DATA, :HORAIN, :HORAFIM);
    END

    SUSPEND;
END^
SET TERM ; ^

GRANT EXECUTE
 ON PROCEDURE CREATE_RESERVA_SIMPLES TO  RS;

GRANT EXECUTE
 ON PROCEDURE CREATE_RESERVA_SIMPLES TO  SYSDBA;


SET TERM ^ ;
ALTER PROCEDURE GET_RESERVAS_SEMANA (
    START Date,
    ENDDT Date,
    AREAID Integer )
RETURNS (
    RESERVAID Integer,
    SALAID Integer,
    DATA Date,
    HORAIN Time,
    HORAFIM Time,
    USUARIOID Integer,
    USUARIO_NOME Varchar(255),
    ASSUNTO Varchar(255),
    DEPTO Varchar(80),
    NOTAS Blob sub_type 1,
    SCHEMEID Integer,
    SEQ Integer,
    TIPO Char(1),
    DATAIN Date,
    DATAFIM Date )
AS
DECLARE VARIABLE I INTEGER;
DECLARE VARIABLE DOW INTEGER;
DECLARE VARIABLE DOM INTEGER;
DECLARE VARIABLE SEG INTEGER;
DECLARE VARIABLE TER INTEGER;
DECLARE VARIABLE QUA INTEGER;
DECLARE VARIABLE QUI INTEGER;
DECLARE VARIABLE SEX INTEGER;
DECLARE VARIABLE SAB INTEGER;
BEGIN  
    DATAIN = NULL;
    DATAFIM = NULL;
    --Reservas Simples
    FOR
        SELECT
            R.RESERVAID, R.SALAID, RS.DATA, RS.HORAIN, RS.HORAFIM,
            R.USUARIOID, U.NOME, R.ASSUNTO, R.DEPTO, R.NOTAS, U.SCHEMEID, R.SEQ, 
            R.TIPO
        FROM
            RESERVAS R 
                JOIN USUARIOS U ON
                    R.USUARIOID = U.USUARIOID
                JOIN RESERVA_SIMPLES RS ON
                    R.RESERVAID = RS.RESERVAID
                JOIN SALAS_AREAS SA ON
                    R.SALAID = SA.SALAID
        WHERE
            (RS.DATA BETWEEN :START AND :ENDDT) AND 
            SA.AREAID = :AREAID
        INTO
            :RESERVAID, :SALAID, :DATA, :HORAIN, :HORAFIM, :USUARIOID,
            :USUARIO_NOME, :ASSUNTO, :DEPTO, :NOTAS, :SCHEMEID, :SEQ,
            :TIPO
    DO
        SUSPEND; 

    -- Reservas Semanais
    FOR
        SELECT
            R.RESERVAID, R.SALAID, RS.DATAIN, RS.DATAFIM, RS.HORAIN, RS.HORAFIM,
            R.USUARIOID, U.NOME, R.ASSUNTO, R.DEPTO, R.NOTAS, U.SCHEMEID, R.SEQ, 
            R.TIPO, RS.SEG, RS.TER, RS.QUA, RS.QUI, RS.SEX, RS.SAB, RS.DOM
        FROM
            RESERVAS R 
                JOIN USUARIOS U ON
                    R.USUARIOID = U.USUARIOID
                JOIN RESERVA_SEMANAL RS ON
                    R.RESERVAID = RS.RESERVAID
                JOIN SALAS_AREAS SA ON
                    R.SALAID = SA.SALAID
        WHERE
            (RS.DATAIN <= :ENDDT) AND
            ((RS.DATAFIM IS NULL) OR (RS.DATAFIM >= :START)) AND
            (SA.AREAID = :AREAID)
        INTO
            :RESERVAID, :SALAID, :DATAIN, :DATAFIM, :HORAIN, :HORAFIM, :USUARIOID,
            :USUARIO_NOME, :ASSUNTO, :DEPTO, :NOTAS, :SCHEMEID, :SEQ,
            :TIPO, :SEG, :TER, :QUA, :QUI, :SEX, :SAB, :DOM
    DO
    BEGIN
        FOR
            SELECT
                DIAS
            FROM
                GET_SEMANAL_DIAS(:RESERVAID, :START, :ENDDT)
            WHERE
                DIAS BETWEEN :START AND :ENDDT
            INTO
                :DATA
            DO
                SUSPEND;
    END
END^
SET TERM ; ^

GRANT EXECUTE
 ON PROCEDURE GET_RESERVAS_SEMANA TO  RS;

GRANT EXECUTE
 ON PROCEDURE GET_RESERVAS_SEMANA TO  SYSDBA;


SET TERM ^ ;
ALTER PROCEDURE GET_SEMANAL_DIAS (
    RESERVAID Integer,
    DATAIN Date,
    DATAFIM Date )
RETURNS (
    DIAS Date )
AS
DECLARE VARIABLE SEG SMALLINT;
DECLARE VARIABLE TER SMALLINT;
DECLARE VARIABLE QUA SMALLINT;
DECLARE VARIABLE QUI SMALLINT;
DECLARE VARIABLE SEX SMALLINT;
DECLARE VARIABLE SAB SMALLINT;
DECLARE VARIABLE DOM SMALLINT;
DECLARE VARIABLE VDATAIN DATE;
DECLARE VARIABLE VDATAFIM DATE;
DECLARE VARIABLE REVESA SMALLINT;
DECLARE VARIABLE I SMALLINT;
BEGIN
  SELECT
        SEG, TER, QUA, QUI, SEX, SAB, DOM,
        DATAIN, DATAFIM, REVESA
  FROM
      RESERVA_SEMANAL
  WHERE
       RESERVAID = :RESERVAID
  INTO
      :SEG, :TER, :QUA, :QUI, :SEX, :SAB, :DOM,
      :VDATAIN, :VDATAFIM, :REVESA;

  IF (DIAS < DATAIN) THEN
     DIAS = DATAIN;
  ELSE
    DIAS = VDATAIN;

  IF (VDATAFIM > DATAFIM) THEN
     VDATAFIM = DATAFIM;

  WHILE (DIAS <= VDATAFIM) DO
  BEGIN
        IF ((REVESA = 0) OR (MOD((DIAS - VDATAIN - EXTRACT(WEEKDAY FROM VDATAIN)) / 7, 2) = 0)) THEN
        BEGIN
            I = EXTRACT(WEEKDAY FROM DIAS);

            IF ((I = 1) AND (SEG = 1)) THEN
                SUSPEND;
            ELSE IF ((I = 2) AND (TER = 1)) THEN
                SUSPEND;
            ELSE IF ((I = 3) AND (QUA = 1)) THEN
                SUSPEND;
            ELSE IF ((I = 4) AND (QUI = 1)) THEN
                SUSPEND;
            ELSE IF ((I = 5) AND (SEX = 1)) THEN
                SUSPEND;
            ELSE IF ((I = 6) AND (SAB = 1)) THEN
                SUSPEND;
            ELSE IF ((I = 0) AND (DOM = 1)) THEN
                SUSPEND;
        END
        
       DIAS = DIAS + 1;
  END
END^
SET TERM ; ^

GRANT EXECUTE
 ON PROCEDURE GET_SEMANAL_DIAS TO  RS;

GRANT EXECUTE
 ON PROCEDURE GET_SEMANAL_DIAS TO  SYSDBA;


INSERT INTO "COLOR_SCHEME"	 ("SCHEMEID", 	"BACKGROUND", 	"FONT", 	"BORDER") VALUES (	0, 	15459244, 	15400960, 	0);
INSERT INTO "COLOR_SCHEME"	 ("SCHEMEID", 	"BACKGROUND", 	"FONT", 	"BORDER") VALUES (	1, 	13107142, 	1998622, 	0);
INSERT INTO "COLOR_SCHEME"	 ("SCHEMEID", 	"BACKGROUND", 	"FONT", 	"BORDER") VALUES (	2, 	16758782, 	6432845, 	0);
INSERT INTO "COLOR_SCHEME"	 ("SCHEMEID", 	"BACKGROUND", 	"FONT", 	"BORDER") VALUES (	3, 	11977983, 	2373755, 	0);
INSERT INTO "COLOR_SCHEME"	 ("SCHEMEID", 	"BACKGROUND", 	"FONT", 	"BORDER") VALUES (	4, 	16772073, 	11971072, 	0);
INSERT INTO "COLOR_SCHEME"	 ("SCHEMEID", 	"BACKGROUND", 	"FONT", 	"BORDER") VALUES (	5, 	16774046, 	7221810, 	0);
INSERT INTO "COLOR_SCHEME"	 ("SCHEMEID", 	"BACKGROUND", 	"FONT", 	"BORDER") VALUES (	6, 	11206624, 	43058, 		0);
INSERT INTO "COLOR_SCHEME"	 ("SCHEMEID", 	"BACKGROUND", 	"FONT", 	"BORDER") VALUES (	7, 	12517266, 	474880, 		0);
INSERT INTO "COLOR_SCHEME"	 ("SCHEMEID", 	"BACKGROUND", 	"FONT", 	"BORDER") VALUES (	8, 	16752546, 	15400968, 	0);
INSERT INTO "COLOR_SCHEME"	 ("SCHEMEID", 	"BACKGROUND", 	"FONT", 	"BORDER") VALUES (	9, 	15460360, 	4867848, 	0);

INSERT INTO MODELOS ("MODELOID", "NOME", "BODY", "ITEM", "FUNDO", "FUNDOALT")
VALUES (GEN_ID("GENMODELOS", 1),
'Default',
'<html>
  <body>
    <div align="center" >
      <h4>%SALA% - <i>%DATA%</i> </h4>
      <table cellspacing="0" border="1" cellpadding="2" align="center" width="90%">
        %BODY%
      </table>
    </div>
  </body>
</html>', 
'<tr bgcolor="%COLOR%">
  <td width="15%"  valign="middle" align="center">
    <table cellspacing="0" border="0" cellpadding="0"  width="100%">
      <tr>
        <td valign="middle" align="center">
          <b><big>%HORAIN%</big></b>
        </td>
      </tr>
      <tr>
        <td valign="middle" align="center">
          <b><big>%HORAFIM%</big></b>
        </td>
      </tr>
    </table>
  </td>
  <td valign="middle" align="center">
    <h2>%ASSUNTO%<br><i>%DEPTO%</i></h2>
  </td>
</tr>', 
'White', 
'#DDDDDD');

INSERT INTO MODELOS ("MODELOID", "NOME", "BODY", "ITEM", "FUNDO", "FUNDOALT")
VALUES (GEN_ID("GENMODELOS", 1),
'Compacto',
'<html>
  <body>
    <div align="center" >
      <h4>%SALA% - <i>%DATA%</i> </h4>
      <table cellspacing="0" border="1" cellpadding="2" align="center" width="90%">
        %BODY%
      </table>
    </div>
  </body>
</html>', 
'<tr bgcolor="%COLOR%">
  <td valign="middle" align="center" width="15%">
    <b>%HORAIN%</b>
  </td>
  <td valign="middle" align="center"  width="15%">
    <b>%HORAFIM%</b>
  </td>
  <td valign="middle" align="center"  width="70%">
    %ASSUNTO%&nbsp;<i>%DEPTO%</i>
  </td>
</tr>',
'White', 
'#DDDDDD');

COMMIT;



CREATE INDEX IDXAREA_AREA ON AREAS (AREA);
GRANT DELETE, INSERT, SELECT, UPDATE
 ON AREAS TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON AREAS TO  SYSDBA WITH GRANT OPTION;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON COLOR_SCHEME TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON COLOR_SCHEME TO  SYSDBA WITH GRANT OPTION;

CREATE INDEX IDXDEL$RESERVASDATA_DEL ON DEL$RESERVAS (DATA_DEL);
CREATE INDEX IDXDEL$RESERVASSEQ ON DEL$RESERVAS (SEQ);
GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON DEL$RESERVAS TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON DEL$RESERVAS TO  SYSDBA WITH GRANT OPTION;

CREATE INDEX IDXMODELONOME ON MODELOS (NOME);
GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON MODELOS TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON MODELOS TO  SYSDBA WITH GRANT OPTION;

ALTER TABLE RESERVAS ADD CONSTRAINT FKSALAS
  FOREIGN KEY (SALAID) REFERENCES SALAS (SALAID) ON UPDATE CASCADE ON DELETE CASCADE;
ALTER TABLE RESERVAS ADD CONSTRAINT FKUSUARIOS
  FOREIGN KEY (USUARIOID) REFERENCES USUARIOS (USUARIOID) ON UPDATE CASCADE ON DELETE CASCADE;
CREATE INDEX IDXRESERVASEQ ON RESERVAS (SEQ);
GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVAS TO PROCEDURE CREATE_RESERVA_SIMPLES;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVAS TO PROCEDURE GET_RESERVAS_SEMANA;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVAS TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVAS TO  SYSDBA WITH GRANT OPTION;

ALTER TABLE RESERVA_MENSAL ADD CONSTRAINT FKRESERVA_MENSAL
  FOREIGN KEY (RESERVAID) REFERENCES RESERVAS (RESERVAID) ON UPDATE CASCADE ON DELETE CASCADE;
CREATE INDEX IDXRESERVA_MENSAL_DATA ON RESERVA_MENSAL (DATAIN,DATAFIM);
CREATE INDEX IDXRESERVA_MENSAL_HORA ON RESERVA_MENSAL (HORAIN,HORAFIM);
GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_MENSAL TO PROCEDURE CREATE_RESERVA_SIMPLES;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_MENSAL TO PROCEDURE GET_RESERVAS_SEMANA;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_MENSAL TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_MENSAL TO  SYSDBA WITH GRANT OPTION;

ALTER TABLE RESERVA_SEMANAL ADD CONSTRAINT FKRESERVA_SEMANAL
  FOREIGN KEY (RESERVAID) REFERENCES RESERVAS (RESERVAID) ON UPDATE CASCADE ON DELETE CASCADE;
ALTER TABLE RESERVA_SEMANAL ADD 
  CHECK ("SEG" IN (0, 1));
ALTER TABLE RESERVA_SEMANAL ADD 
  CHECK ("TER" IN (0, 1));
ALTER TABLE RESERVA_SEMANAL ADD 
  CHECK ("QUA" IN (0, 1));
ALTER TABLE RESERVA_SEMANAL ADD 
  CHECK ("QUI" IN (0, 1));
ALTER TABLE RESERVA_SEMANAL ADD 
  CHECK ("SEX" IN (0, 1));
ALTER TABLE RESERVA_SEMANAL ADD 
  CHECK ("SAB" IN (0, 1));
ALTER TABLE RESERVA_SEMANAL ADD 
  CHECK ("DOM" IN (0, 1));
ALTER TABLE RESERVA_SEMANAL ADD 
  CHECK ("REVESA" IN (0, 1));
CREATE INDEX IDXRESERVA_SEMANAL_DATA ON RESERVA_SEMANAL (DATAIN,DATAFIM);
CREATE INDEX IDXRESERVA_SEMANAL_HORA ON RESERVA_SEMANAL (HORAIN,HORAFIM);
GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_SEMANAL TO PROCEDURE CREATE_RESERVA_SIMPLES;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_SEMANAL TO PROCEDURE GET_RESERVAS_SEMANA;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_SEMANAL TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_SEMANAL TO  SYSDBA WITH GRANT OPTION;

ALTER TABLE RESERVA_SIMPLES ADD CONSTRAINT FKRESERVA_SIMPLES
  FOREIGN KEY (RESERVAID) REFERENCES RESERVAS (RESERVAID) ON UPDATE CASCADE ON DELETE CASCADE;
CREATE INDEX IDXRESERVA_SIMPLES ON RESERVA_SIMPLES (DATA,HORAIN);
GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_SIMPLES TO PROCEDURE CREATE_RESERVA_SIMPLES;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_SIMPLES TO PROCEDURE GET_RESERVAS_SEMANA;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_SIMPLES TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON RESERVA_SIMPLES TO  SYSDBA WITH GRANT OPTION;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON SALAS TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON SALAS TO  SYSDBA WITH GRANT OPTION;

ALTER TABLE SALAS_AREAS ADD CONSTRAINT FKSALAS_AREAS_AREA
  FOREIGN KEY (AREAID) REFERENCES AREAS (AREAID) ON UPDATE CASCADE ON DELETE CASCADE;
ALTER TABLE SALAS_AREAS ADD CONSTRAINT FKSALAS_AREAS_SALA
  FOREIGN KEY (SALAID) REFERENCES SALAS (SALAID) ON UPDATE CASCADE ON DELETE CASCADE;
GRANT DELETE, INSERT, SELECT, UPDATE
 ON SALAS_AREAS TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON SALAS_AREAS TO  SYSDBA WITH GRANT OPTION;

ALTER TABLE USUARIOS ADD CONSTRAINT FK_SCHEME_USUARIOS
  FOREIGN KEY (SCHEMEID) REFERENCES COLOR_SCHEME (SCHEMEID) ON UPDATE CASCADE ON DELETE SET NULL;
CREATE INDEX IDXUSUARIO_LOGIN ON USUARIOS (LOGIN);
GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON USUARIOS TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON USUARIOS TO  SYSDBA WITH GRANT OPTION;

ALTER TABLE USUARIOS_AREAS ADD CONSTRAINT FKUSUARIOS_AREAS_AREA
  FOREIGN KEY (AREAID) REFERENCES AREAS (AREAID) ON UPDATE CASCADE ON DELETE CASCADE;
ALTER TABLE USUARIOS_AREAS ADD CONSTRAINT FKUSUARIOS_AREAS_USUARIO
  FOREIGN KEY (USUARIOID) REFERENCES USUARIOS (USUARIOID) ON UPDATE CASCADE ON DELETE CASCADE;
GRANT DELETE, INSERT, SELECT, UPDATE
 ON USUARIOS_AREAS TO  RS;

GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON USUARIOS_AREAS TO  SYSDBA WITH GRANT OPTION;

COMMIT;
