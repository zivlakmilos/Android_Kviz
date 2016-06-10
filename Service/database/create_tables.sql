/*
 *
 * Autor: Milos Zivlak (zivlakmilos@gmail.rs,
 *                      zivlakmilos@sbb.rs
 *                      zi@zivlakmilos.ddns.net)
 *
 * Skripta koja kreira tabela za android kviz
 *
 * Database: MySql
 *  host: zivlakmilos.ddns.net
 *  port: 3306 (default port)
 *  username: androidkviz
 *  password: Android_Kviz.5001
 *  admin: Milos Zivlak (admin@zivlakmilos.ddns.net)
 *
 * DatabaseName: android_kviz
 */

/* Koristi bazu android_kviz */
USE android_kviz;

/*****************************
 * KREIRANJE OSNOVNIH TABELA *
 *****************************/

/* Kreiranje tabele za kvizove (nazive kvizova) */
CREATE TABLE IF NOT EXISTS nazivi_kvizova
(
    id int NOT NULL AUTO_INCREMENT,
    naziv varchar(255) NULL,
    PRIMARY KEY(id)
) DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

/* Kreiranje tabele sa pitanjima */
CREATE TABLE IF NOT EXISTS ko_zna_zna
(
    id int NOT NULL AUTO_INCREMENT,
    pitanje varchar(255) NULL,
    odgovor varchar(255) NULL,
    PRIMARY KEY(id)
) DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

/* Kreiranje tabele sa pitanjima (sa zadatim odgovorima) */
CREATE TABLE IF NOT EXISTS brzi_prsti
(
    id int NOT NULL AUTO_INCREMENT,
    pitanje varchar(255) NULL,
    a varchar(50) NULL,
    b varchar(50) NULL,
    c varchar(50) NULL,
    d varchar(50) NULL,
    odgovor varchar(1) NULL,
    PRIMARY KEY(id)
) DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

/* Asocijacije */
CREATE TABLE IF NOT EXISTS asocijacije
(
    id int NOT NULL AUTO_INCREMENT,
    a1 varchar(50) NULL,
    a2 varchar(50) NULL,
    a3 varchar(50) NULL,
    a4 varchar(50) NULL,
    b1 varchar(50) NULL,
    b2 varchar(50) NULL,
    b3 varchar(50) NULL,
    b4 varchar(50) NULL,
    c1 varchar(50) NULL,
    c2 varchar(50) NULL,
    c3 varchar(50) NULL,
    c4 varchar(50) NULL,
    d1 varchar(50) NULL,
    d2 varchar(50) NULL,
    d3 varchar(50) NULL,
    d4 varchar(50) NULL,
    a varchar(50) NULL,
    b varchar(50) NULL,
    c varchar(50) NULL,
    d varchar(50) NULL,
    konacno varchar(50) NULL,
    PRIMARY KEY(id)
) DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

/**************************************
 * SPAJANJE TABELA, KREIRANJE SPOJEVA *
 **************************************/

/*
 * Spajanje svih pitanja i kviza, kao i tip pitanja:
 *  1 - Ko zna zna
 *  2 - Brzi prsti
 *  3 - Asocijacije
 */
CREATE TABLE IF NOT EXISTS kviz_pitanja
(
    id int NOT NULL AUTO_INCREMENT,
    tip int NOT NULL,
    kviz_id int NOT NULL,
    pitanje_id int NOT NULL,
    PRIMARY KEY(id)
) DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;
