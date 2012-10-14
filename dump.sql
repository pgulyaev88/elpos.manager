--
-- PostgreSQL database dump
--

SET statement_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner:
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner:
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

--
-- Name: D_BIGINTEGER; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_BIGINTEGER" AS bigint;


ALTER DOMAIN public."D_BIGINTEGER" OWNER TO elpos;

--
-- Name: D_BOOL; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_BOOL" AS boolean;


ALTER DOMAIN public."D_BOOL" OWNER TO elpos;

--
-- Name: D_DATE; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_DATE" AS date;


ALTER DOMAIN public."D_DATE" OWNER TO elpos;

--
-- Name: D_INTEGER; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_INTEGER" AS integer;


ALTER DOMAIN public."D_INTEGER" OWNER TO elpos;

--
-- Name: D_MONEY; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_MONEY" AS money;


ALTER DOMAIN public."D_MONEY" OWNER TO elpos;

--
-- Name: D_NUMERIC12; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_NUMERIC12" AS numeric(12,2);


ALTER DOMAIN public."D_NUMERIC12" OWNER TO elpos;

--
-- Name: D_SMALLINT; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_SMALLINT" AS smallint;


ALTER DOMAIN public."D_SMALLINT" OWNER TO elpos;

--
-- Name: D_STRING10; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_STRING10" AS character varying(10);


ALTER DOMAIN public."D_STRING10" OWNER TO elpos;

--
-- Name: D_STRING100; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_STRING100" AS character varying(100);


ALTER DOMAIN public."D_STRING100" OWNER TO elpos;

--
-- Name: D_STRING15; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_STRING15" AS character varying(15);


ALTER DOMAIN public."D_STRING15" OWNER TO elpos;

--
-- Name: D_STRING25; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_STRING25" AS character varying(25);


ALTER DOMAIN public."D_STRING25" OWNER TO elpos;

--
-- Name: D_STRING250; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_STRING250" AS character varying(250);


ALTER DOMAIN public."D_STRING250" OWNER TO elpos;

--
-- Name: D_STRING5; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_STRING5" AS character varying(5);


ALTER DOMAIN public."D_STRING5" OWNER TO elpos;

--
-- Name: D_STRING50; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_STRING50" AS character varying(50);


ALTER DOMAIN public."D_STRING50" OWNER TO elpos;

--
-- Name: D_STRING500; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_STRING500" AS character varying(500);


ALTER DOMAIN public."D_STRING500" OWNER TO elpos;

--
-- Name: D_TIME; Type: DOMAIN; Schema: public; Owner: elpos
--

CREATE DOMAIN "D_TIME" AS time without time zone;


ALTER DOMAIN public."D_TIME" OWNER TO elpos;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: address; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE address (
    address_id integer NOT NULL,
    street_id "D_INTEGER",
    house "D_SMALLINT",
    building "D_SMALLINT",
    entrance "D_SMALLINT",
    floor "D_SMALLINT",
    flat "D_STRING5",
    code_entrance "D_STRING15",
    deleted "D_BOOL"
);


ALTER TABLE public.address OWNER TO elpos;

--
-- Name: address_address_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE address_address_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.address_address_id_seq OWNER TO elpos;

--
-- Name: address_address_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE address_address_id_seq OWNED BY address.address_id;


--
-- Name: address_address_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('address_address_id_seq', 1, false);


--
-- Name: categories; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE categories (
    name "D_STRING50",
    altname "D_STRING50",
    deleted "D_BOOL",
    code "D_INTEGER",
    category_id integer NOT NULL
);


ALTER TABLE public.categories OWNER TO elpos;

--
-- Name: categories_category_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE categories_category_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.categories_category_id_seq OWNER TO elpos;

--
-- Name: categories_category_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE categories_category_id_seq OWNED BY categories.category_id;


--
-- Name: categories_category_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('categories_category_id_seq', 39, true);


--
-- Name: clients; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE clients (
    client_id integer NOT NULL,
    f_name "D_STRING25",
    m_name "D_STRING25",
    l_name "D_STRING25",
    phone_id "D_INTEGER",
    adderss_id "D_INTEGER",
    birthday "D_DATE",
    vip "D_BOOL",
    deleted "D_BOOL"
);


ALTER TABLE public.clients OWNER TO elpos;

--
-- Name: clients_client_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE clients_client_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.clients_client_id_seq OWNER TO elpos;

--
-- Name: clients_client_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE clients_client_id_seq OWNED BY clients.client_id;


--
-- Name: clients_client_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('clients_client_id_seq', 1, false);


--
-- Name: currencies; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE currencies (
    currency_id integer NOT NULL,
    currency_name "D_STRING25",
    currency_altname "D_STRING25",
    currency_rate "D_MONEY",
    currency_national "D_BOOL",
    deleted "D_BOOL",
    currency_code "D_INTEGER"
);


ALTER TABLE public.currencies OWNER TO elpos;

--
-- Name: currencies_currency_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE currencies_currency_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.currencies_currency_id_seq OWNER TO elpos;

--
-- Name: currencies_currency_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE currencies_currency_id_seq OWNED BY currencies.currency_id;


--
-- Name: currencies_currency_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('currencies_currency_id_seq', 95, true);


--
-- Name: discounts; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE discounts (
    discount_id integer NOT NULL,
    discount_name "D_STRING25",
    discount_percent "D_SMALLINT",
    deleted "D_BOOL"
);


ALTER TABLE public.discounts OWNER TO elpos;

--
-- Name: discounts_discount_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE discounts_discount_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.discounts_discount_id_seq OWNER TO elpos;

--
-- Name: discounts_discount_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE discounts_discount_id_seq OWNED BY discounts.discount_id;


--
-- Name: discounts_discount_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('discounts_discount_id_seq', 3, true);


--
-- Name: menu_groups; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE menu_groups (
    menu_group_id integer NOT NULL,
    group_name "D_STRING25",
    group_alt_name "D_STRING25",
    deleted "D_BOOL"
);


ALTER TABLE public.menu_groups OWNER TO elpos;

--
-- Name: menu_groups_menu_group_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE menu_groups_menu_group_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.menu_groups_menu_group_id_seq OWNER TO elpos;

--
-- Name: menu_groups_menu_group_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE menu_groups_menu_group_id_seq OWNED BY menu_groups.menu_group_id;


--
-- Name: menu_groups_menu_group_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('menu_groups_menu_group_id_seq', 1, true);


--
-- Name: menus; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE menus (
    menu_id integer NOT NULL,
    name "D_STRING100",
    altname "D_STRING50",
    price "D_MONEY",
    category_id "D_INTEGER",
    menu_group_id "D_INTEGER",
    deleted "D_BOOL"
);


ALTER TABLE public.menus OWNER TO elpos;

--
-- Name: menus_menu_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE menus_menu_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.menus_menu_id_seq OWNER TO elpos;

--
-- Name: menus_menu_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE menus_menu_id_seq OWNED BY menus.menu_id;


--
-- Name: menus_menu_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('menus_menu_id_seq', 1, true);


--
-- Name: order_details; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE order_details (
    order_details_id integer NOT NULL
);


ALTER TABLE public.order_details OWNER TO elpos;

--
-- Name: order_details_order_details_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE order_details_order_details_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.order_details_order_details_id_seq OWNER TO elpos;

--
-- Name: order_details_order_details_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE order_details_order_details_id_seq OWNED BY order_details.order_details_id;


--
-- Name: order_details_order_details_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('order_details_order_details_id_seq', 1, false);


--
-- Name: order_id_sq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE order_id_sq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.order_id_sq OWNER TO elpos;

--
-- Name: order_id_sq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('order_id_sq', 1, false);


--
-- Name: orders; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE orders (
    order_id integer NOT NULL
);


ALTER TABLE public.orders OWNER TO elpos;

--
-- Name: orders_order_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE orders_order_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.orders_order_id_seq OWNER TO elpos;

--
-- Name: orders_order_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE orders_order_id_seq OWNED BY orders.order_id;


--
-- Name: orders_order_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('orders_order_id_seq', 1, false);


--
-- Name: phones; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE phones (
    phone_id integer NOT NULL
);


ALTER TABLE public.phones OWNER TO elpos;

--
-- Name: phones_phone_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE phones_phone_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.phones_phone_id_seq OWNER TO elpos;

--
-- Name: phones_phone_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE phones_phone_id_seq OWNED BY phones.phone_id;


--
-- Name: phones_phone_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('phones_phone_id_seq', 1, false);


--
-- Name: restaurants; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE restaurants (
    restaurant_id integer NOT NULL,
    rest_name "D_STRING50",
    rest_address_id "D_INTEGER",
    open_time "D_TIME",
    close_time "D_TIME",
    work_day_mon "D_BOOL",
    work_day_tue "D_BOOL",
    work_day_wed "D_BOOL",
    work_day_thu "D_BOOL",
    work_day_fri "D_BOOL",
    work_day_sun "D_BOOL",
    work_day_sat "D_BOOL",
    deleted "D_BOOL"
);


ALTER TABLE public.restaurants OWNER TO elpos;

--
-- Name: restaurants_restaurant_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE restaurants_restaurant_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.restaurants_restaurant_id_seq OWNER TO elpos;

--
-- Name: restaurants_restaurant_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE restaurants_restaurant_id_seq OWNED BY restaurants.restaurant_id;


--
-- Name: restaurants_restaurant_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('restaurants_restaurant_id_seq', 1, false);


--
-- Name: street; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE street (
    street_id integer NOT NULL,
    street_name "D_STRING250",
    count_house "D_INTEGER",
    distance "D_NUMERIC12"
);


ALTER TABLE public.street OWNER TO elpos;

--
-- Name: street_street_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE street_street_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.street_street_id_seq OWNER TO elpos;

--
-- Name: street_street_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE street_street_id_seq OWNED BY street.street_id;


--
-- Name: street_street_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('street_street_id_seq', 1, true);


--
-- Name: zone_details; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE zone_details (
    zone_details_id integer NOT NULL
);


ALTER TABLE public.zone_details OWNER TO elpos;

--
-- Name: zone_details_zone_details_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE zone_details_zone_details_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.zone_details_zone_details_id_seq OWNER TO elpos;

--
-- Name: zone_details_zone_details_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE zone_details_zone_details_id_seq OWNED BY zone_details.zone_details_id;


--
-- Name: zone_details_zone_details_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('zone_details_zone_details_id_seq', 1, false);


--
-- Name: zones; Type: TABLE; Schema: public; Owner: elpos; Tablespace:
--

CREATE TABLE zones (
    zone_id integer NOT NULL
);


ALTER TABLE public.zones OWNER TO elpos;

--
-- Name: zones_zone_id_seq; Type: SEQUENCE; Schema: public; Owner: elpos
--

CREATE SEQUENCE zones_zone_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.zones_zone_id_seq OWNER TO elpos;

--
-- Name: zones_zone_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: elpos
--

ALTER SEQUENCE zones_zone_id_seq OWNED BY zones.zone_id;


--
-- Name: zones_zone_id_seq; Type: SEQUENCE SET; Schema: public; Owner: elpos
--

SELECT pg_catalog.setval('zones_zone_id_seq', 1, false);


--
-- Name: address_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY address ALTER COLUMN address_id SET DEFAULT nextval('address_address_id_seq'::regclass);


--
-- Name: category_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY categories ALTER COLUMN category_id SET DEFAULT nextval('categories_category_id_seq'::regclass);


--
-- Name: client_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY clients ALTER COLUMN client_id SET DEFAULT nextval('clients_client_id_seq'::regclass);


--
-- Name: currency_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY currencies ALTER COLUMN currency_id SET DEFAULT nextval('currencies_currency_id_seq'::regclass);


--
-- Name: discount_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY discounts ALTER COLUMN discount_id SET DEFAULT nextval('discounts_discount_id_seq'::regclass);


--
-- Name: menu_group_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY menu_groups ALTER COLUMN menu_group_id SET DEFAULT nextval('menu_groups_menu_group_id_seq'::regclass);


--
-- Name: menu_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY menus ALTER COLUMN menu_id SET DEFAULT nextval('menus_menu_id_seq'::regclass);


--
-- Name: order_details_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY order_details ALTER COLUMN order_details_id SET DEFAULT nextval('order_details_order_details_id_seq'::regclass);


--
-- Name: order_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY orders ALTER COLUMN order_id SET DEFAULT nextval('orders_order_id_seq'::regclass);


--
-- Name: phone_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY phones ALTER COLUMN phone_id SET DEFAULT nextval('phones_phone_id_seq'::regclass);


--
-- Name: restaurant_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY restaurants ALTER COLUMN restaurant_id SET DEFAULT nextval('restaurants_restaurant_id_seq'::regclass);


--
-- Name: street_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY street ALTER COLUMN street_id SET DEFAULT nextval('street_street_id_seq'::regclass);


--
-- Name: zone_details_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY zone_details ALTER COLUMN zone_details_id SET DEFAULT nextval('zone_details_zone_details_id_seq'::regclass);


--
-- Name: zone_id; Type: DEFAULT; Schema: public; Owner: elpos
--

ALTER TABLE ONLY zones ALTER COLUMN zone_id SET DEFAULT nextval('zones_zone_id_seq'::regclass);


--
-- Data for Name: address; Type: TABLE DATA; Schema: public; Owner: elpos
--



--
-- Data for Name: categories; Type: TABLE DATA; Schema: public; Owner: elpos
--

INSERT INTO categories VALUES ('Bar', '', false, 1122, 38);
INSERT INTO categories VALUES ('Pizza', '', true, 54564, 39);


--
-- Data for Name: clients; Type: TABLE DATA; Schema: public; Owner: elpos
--



--
-- Data for Name: currencies; Type: TABLE DATA; Schema: public; Owner: elpos
--

INSERT INTO currencies VALUES (92, 'adfad', 'eda', 'руб12.20', false, true, 123123);
INSERT INTO currencies VALUES (93, '', '', 'руб13 131 231.23', false, true, 0);
INSERT INTO currencies VALUES (95, 'sfse', 'qew', 'руб14 123 123.12', false, true, 124123);
INSERT INTO currencies VALUES (94, 'wedaef', 'gha', 'руб10.20', true, true, 125123);


--
-- Data for Name: discounts; Type: TABLE DATA; Schema: public; Owner: elpos
--

INSERT INTO discounts VALUES (3, 'wq', 11, false);
INSERT INTO discounts VALUES (2, 'qwe', 15, false);
INSERT INTO discounts VALUES (1, 'asd', 16, false);


--
-- Data for Name: menu_groups; Type: TABLE DATA; Schema: public; Owner: elpos
--

INSERT INTO menu_groups VALUES (1, 'Beer', NULL, false);


--
-- Data for Name: menus; Type: TABLE DATA; Schema: public; Owner: elpos
--



--
-- Data for Name: order_details; Type: TABLE DATA; Schema: public; Owner: elpos
--



--
-- Data for Name: orders; Type: TABLE DATA; Schema: public; Owner: elpos
--



--
-- Data for Name: phones; Type: TABLE DATA; Schema: public; Owner: elpos
--



--
-- Data for Name: restaurants; Type: TABLE DATA; Schema: public; Owner: elpos
--



--
-- Data for Name: street; Type: TABLE DATA; Schema: public; Owner: elpos
--

INSERT INTO street VALUES (1, 'new street ', 23, 25.00);


--
-- Data for Name: zone_details; Type: TABLE DATA; Schema: public; Owner: elpos
--



--
-- Data for Name: zones; Type: TABLE DATA; Schema: public; Owner: elpos
--



--
-- Name: address_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY address
    ADD CONSTRAINT address_pkey PRIMARY KEY (address_id);


--
-- Name: clients_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY clients
    ADD CONSTRAINT clients_pkey PRIMARY KEY (client_id);


--
-- Name: currencies_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY currencies
    ADD CONSTRAINT currencies_pkey PRIMARY KEY (currency_id);


--
-- Name: discounts_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY discounts
    ADD CONSTRAINT discounts_pkey PRIMARY KEY (discount_id);


--
-- Name: menu_groups_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY menu_groups
    ADD CONSTRAINT menu_groups_pkey PRIMARY KEY (menu_group_id);


--
-- Name: menus_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY menus
    ADD CONSTRAINT menus_pkey PRIMARY KEY (menu_id);


--
-- Name: order_details_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY order_details
    ADD CONSTRAINT order_details_pkey PRIMARY KEY (order_details_id);


--
-- Name: orders_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY orders
    ADD CONSTRAINT orders_pkey PRIMARY KEY (order_id);


--
-- Name: phones_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY phones
    ADD CONSTRAINT phones_pkey PRIMARY KEY (phone_id);


--
-- Name: restaurants_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY restaurants
    ADD CONSTRAINT restaurants_pkey PRIMARY KEY (restaurant_id);


--
-- Name: street_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY street
    ADD CONSTRAINT street_pkey PRIMARY KEY (street_id);


--
-- Name: zone_details_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY zone_details
    ADD CONSTRAINT zone_details_pkey PRIMARY KEY (zone_details_id);


--
-- Name: zones_pkey; Type: CONSTRAINT; Schema: public; Owner: elpos; Tablespace:
--

ALTER TABLE ONLY zones
    ADD CONSTRAINT zones_pkey PRIMARY KEY (zone_id);


--
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO admin;
GRANT ALL ON SCHEMA public TO elpos;
GRANT ALL ON SCHEMA public TO PUBLIC;


--
-- Name: address; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE address FROM PUBLIC;
REVOKE ALL ON TABLE address FROM elpos;
GRANT ALL ON TABLE address TO elpos;
GRANT ALL ON TABLE address TO PUBLIC;


--
-- Name: address_address_id_seq; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON SEQUENCE address_address_id_seq FROM PUBLIC;
REVOKE ALL ON SEQUENCE address_address_id_seq FROM elpos;
GRANT ALL ON SEQUENCE address_address_id_seq TO elpos;
GRANT ALL ON SEQUENCE address_address_id_seq TO PUBLIC;


--
-- Name: categories; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE categories FROM PUBLIC;
REVOKE ALL ON TABLE categories FROM elpos;
GRANT ALL ON TABLE categories TO elpos;
GRANT ALL ON TABLE categories TO PUBLIC;


--
-- Name: clients; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE clients FROM PUBLIC;
REVOKE ALL ON TABLE clients FROM elpos;
GRANT ALL ON TABLE clients TO elpos;
GRANT ALL ON TABLE clients TO PUBLIC;


--
-- Name: clients_client_id_seq; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON SEQUENCE clients_client_id_seq FROM PUBLIC;
REVOKE ALL ON SEQUENCE clients_client_id_seq FROM elpos;
GRANT ALL ON SEQUENCE clients_client_id_seq TO elpos;
GRANT ALL ON SEQUENCE clients_client_id_seq TO PUBLIC;


--
-- Name: currencies; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE currencies FROM PUBLIC;
REVOKE ALL ON TABLE currencies FROM elpos;
GRANT ALL ON TABLE currencies TO elpos;
GRANT ALL ON TABLE currencies TO PUBLIC;


--
-- Name: discounts; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE discounts FROM PUBLIC;
REVOKE ALL ON TABLE discounts FROM elpos;
GRANT ALL ON TABLE discounts TO elpos;
GRANT ALL ON TABLE discounts TO PUBLIC;


--
-- Name: discounts_discount_id_seq; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON SEQUENCE discounts_discount_id_seq FROM PUBLIC;
REVOKE ALL ON SEQUENCE discounts_discount_id_seq FROM elpos;
GRANT ALL ON SEQUENCE discounts_discount_id_seq TO elpos;
GRANT ALL ON SEQUENCE discounts_discount_id_seq TO PUBLIC;


--
-- Name: menu_groups; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE menu_groups FROM PUBLIC;
REVOKE ALL ON TABLE menu_groups FROM elpos;
GRANT ALL ON TABLE menu_groups TO elpos;
GRANT ALL ON TABLE menu_groups TO PUBLIC;


--
-- Name: menu_groups_menu_group_id_seq; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON SEQUENCE menu_groups_menu_group_id_seq FROM PUBLIC;
REVOKE ALL ON SEQUENCE menu_groups_menu_group_id_seq FROM elpos;
GRANT ALL ON SEQUENCE menu_groups_menu_group_id_seq TO elpos;
GRANT ALL ON SEQUENCE menu_groups_menu_group_id_seq TO PUBLIC;


--
-- Name: menus; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE menus FROM PUBLIC;
REVOKE ALL ON TABLE menus FROM elpos;
GRANT ALL ON TABLE menus TO elpos;
GRANT ALL ON TABLE menus TO PUBLIC;


--
-- Name: menus_menu_id_seq; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON SEQUENCE menus_menu_id_seq FROM PUBLIC;
REVOKE ALL ON SEQUENCE menus_menu_id_seq FROM elpos;
GRANT ALL ON SEQUENCE menus_menu_id_seq TO elpos;
GRANT ALL ON SEQUENCE menus_menu_id_seq TO PUBLIC;


--
-- Name: order_details; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE order_details FROM PUBLIC;
REVOKE ALL ON TABLE order_details FROM elpos;
GRANT ALL ON TABLE order_details TO elpos;
GRANT ALL ON TABLE order_details TO PUBLIC;
GRANT ALL ON TABLE order_details TO postgres;


--
-- Name: orders; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE orders FROM PUBLIC;
REVOKE ALL ON TABLE orders FROM elpos;
GRANT ALL ON TABLE orders TO elpos;
GRANT ALL ON TABLE orders TO PUBLIC;


--
-- Name: phones; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE phones FROM PUBLIC;
REVOKE ALL ON TABLE phones FROM elpos;
GRANT ALL ON TABLE phones TO elpos;
GRANT ALL ON TABLE phones TO PUBLIC;


--
-- Name: restaurants; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE restaurants FROM PUBLIC;
REVOKE ALL ON TABLE restaurants FROM elpos;
GRANT ALL ON TABLE restaurants TO elpos;
GRANT ALL ON TABLE restaurants TO PUBLIC;


--
-- Name: street; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE street FROM PUBLIC;
REVOKE ALL ON TABLE street FROM elpos;
GRANT ALL ON TABLE street TO elpos;
GRANT ALL ON TABLE street TO PUBLIC;


--
-- Name: zone_details; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE zone_details FROM PUBLIC;
REVOKE ALL ON TABLE zone_details FROM elpos;
GRANT ALL ON TABLE zone_details TO elpos;
GRANT ALL ON TABLE zone_details TO PUBLIC;


--
-- Name: zones; Type: ACL; Schema: public; Owner: elpos
--

REVOKE ALL ON TABLE zones FROM PUBLIC;
REVOKE ALL ON TABLE zones FROM elpos;
GRANT ALL ON TABLE zones TO elpos;
GRANT ALL ON TABLE zones TO PUBLIC;


--
-- PostgreSQL database dump complete
--

