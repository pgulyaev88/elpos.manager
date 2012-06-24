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

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: address; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE address (
    address_id integer NOT NULL,
    street_id integer,
    house integer,
    building integer,
    entrance integer,
    floor integer,
    flat integer,
    code_entrance character varying(16),
    deleted boolean
);


ALTER TABLE public.address OWNER TO admin;

--
-- Name: address_address_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE address_address_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.address_address_id_seq OWNER TO admin;

--
-- Name: address_address_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE address_address_id_seq OWNED BY address.address_id;


--
-- Name: address_address_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('address_address_id_seq', 1, false);


--
-- Name: categories; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE categories (
    name character varying(127),
    altname character varying(127),
    deleted boolean,
    code integer,
    category_id integer NOT NULL
);


ALTER TABLE public.categories OWNER TO admin;

--
-- Name: categories_category_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE categories_category_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.categories_category_id_seq OWNER TO admin;

--
-- Name: categories_category_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE categories_category_id_seq OWNED BY categories.category_id;


--
-- Name: categories_category_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('categories_category_id_seq', 39, true);


--
-- Name: clients; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE clients (
    client_id integer NOT NULL,
    f_name character varying(32),
    m_name character varying(32),
    l_name character varying(32),
    phone_id integer,
    adderss_id integer,
    birthday date,
    vip boolean,
    deleted boolean
);


ALTER TABLE public.clients OWNER TO admin;

--
-- Name: clients_client_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE clients_client_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.clients_client_id_seq OWNER TO admin;

--
-- Name: clients_client_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE clients_client_id_seq OWNED BY clients.client_id;


--
-- Name: clients_client_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('clients_client_id_seq', 1, false);


--
-- Name: currencies; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE currencies (
    currency_id integer NOT NULL,
    currency_name character varying(32),
    currency_altname character varying(32),
    currency_rate numeric(11,2),
    currency_national boolean,
    deleted boolean,
    currency_code integer
);


ALTER TABLE public.currencies OWNER TO admin;

--
-- Name: currencies_currency_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE currencies_currency_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.currencies_currency_id_seq OWNER TO admin;

--
-- Name: currencies_currency_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE currencies_currency_id_seq OWNED BY currencies.currency_id;


--
-- Name: currencies_currency_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('currencies_currency_id_seq', 95, true);


--
-- Name: discounts; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE discounts (
    discount_id integer NOT NULL,
    discount_name character varying(32),
    discount_percent integer,
    deleted boolean
);


ALTER TABLE public.discounts OWNER TO admin;

--
-- Name: discounts_discount_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE discounts_discount_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.discounts_discount_id_seq OWNER TO admin;

--
-- Name: discounts_discount_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE discounts_discount_id_seq OWNED BY discounts.discount_id;


--
-- Name: discounts_discount_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('discounts_discount_id_seq', 3, true);


--
-- Name: menu_groups; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE menu_groups (
    menu_group_id integer NOT NULL,
    group_name character varying(32),
    group_alt_name character varying(32),
    deleted boolean
);


ALTER TABLE public.menu_groups OWNER TO admin;

--
-- Name: menu_groups_menu_group_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE menu_groups_menu_group_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.menu_groups_menu_group_id_seq OWNER TO admin;

--
-- Name: menu_groups_menu_group_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE menu_groups_menu_group_id_seq OWNED BY menu_groups.menu_group_id;


--
-- Name: menu_groups_menu_group_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('menu_groups_menu_group_id_seq', 1, true);


--
-- Name: menus; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE menus (
    menu_id integer NOT NULL,
    name character varying(127),
    altname character varying(127),
    price double precision,
    category_id integer,
    menu_group_id integer,
    deleted boolean
);


ALTER TABLE public.menus OWNER TO admin;

--
-- Name: menus_menu_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE menus_menu_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.menus_menu_id_seq OWNER TO admin;

--
-- Name: menus_menu_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE menus_menu_id_seq OWNED BY menus.menu_id;


--
-- Name: menus_menu_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('menus_menu_id_seq', 1, true);


--
-- Name: order_details; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE order_details (
    order_details_id integer NOT NULL
);


ALTER TABLE public.order_details OWNER TO admin;

--
-- Name: order_details_order_details_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE order_details_order_details_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.order_details_order_details_id_seq OWNER TO admin;

--
-- Name: order_details_order_details_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE order_details_order_details_id_seq OWNED BY order_details.order_details_id;


--
-- Name: order_details_order_details_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('order_details_order_details_id_seq', 1, false);


--
-- Name: order_id_sq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE order_id_sq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.order_id_sq OWNER TO admin;

--
-- Name: order_id_sq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('order_id_sq', 1, false);


--
-- Name: orders; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE orders (
    order_id integer NOT NULL
);


ALTER TABLE public.orders OWNER TO admin;

--
-- Name: orders_order_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE orders_order_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.orders_order_id_seq OWNER TO admin;

--
-- Name: orders_order_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE orders_order_id_seq OWNED BY orders.order_id;


--
-- Name: orders_order_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('orders_order_id_seq', 1, false);


--
-- Name: phones; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE phones (
    phone_id integer NOT NULL
);


ALTER TABLE public.phones OWNER TO admin;

--
-- Name: phones_phone_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE phones_phone_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.phones_phone_id_seq OWNER TO admin;

--
-- Name: phones_phone_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE phones_phone_id_seq OWNED BY phones.phone_id;


--
-- Name: phones_phone_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('phones_phone_id_seq', 1, false);


--
-- Name: restaurants; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE restaurants (
    restaurant_id integer NOT NULL,
    rest_name character varying(255),
    rest_address_id integer,
    open_time time without time zone,
    close_time time without time zone,
    work_day_mon boolean,
    work_day_tue boolean,
    work_day_wed boolean,
    work_day_thu boolean,
    work_day_fri boolean,
    work_day_sun boolean,
    work_day_sat boolean,
    deleted boolean
);


ALTER TABLE public.restaurants OWNER TO admin;

--
-- Name: restaurants_restaurant_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE restaurants_restaurant_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.restaurants_restaurant_id_seq OWNER TO admin;

--
-- Name: restaurants_restaurant_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE restaurants_restaurant_id_seq OWNED BY restaurants.restaurant_id;


--
-- Name: restaurants_restaurant_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('restaurants_restaurant_id_seq', 1, false);


--
-- Name: street; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE street (
    street_id integer NOT NULL,
    street_name character varying(255),
    count_house integer,
    distance double precision
);


ALTER TABLE public.street OWNER TO admin;

--
-- Name: street_street_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE street_street_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.street_street_id_seq OWNER TO admin;

--
-- Name: street_street_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE street_street_id_seq OWNED BY street.street_id;


--
-- Name: street_street_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('street_street_id_seq', 1, true);


--
-- Name: zone_details; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE zone_details (
    zone_details_id integer NOT NULL
);


ALTER TABLE public.zone_details OWNER TO admin;

--
-- Name: zone_details_zone_details_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE zone_details_zone_details_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.zone_details_zone_details_id_seq OWNER TO admin;

--
-- Name: zone_details_zone_details_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE zone_details_zone_details_id_seq OWNED BY zone_details.zone_details_id;


--
-- Name: zone_details_zone_details_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('zone_details_zone_details_id_seq', 1, false);


--
-- Name: zones; Type: TABLE; Schema: public; Owner: admin; Tablespace: 
--

CREATE TABLE zones (
    zone_id integer NOT NULL
);


ALTER TABLE public.zones OWNER TO admin;

--
-- Name: zones_zone_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE zones_zone_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.zones_zone_id_seq OWNER TO admin;

--
-- Name: zones_zone_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE zones_zone_id_seq OWNED BY zones.zone_id;


--
-- Name: zones_zone_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('zones_zone_id_seq', 1, false);


--
-- Name: address_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY address ALTER COLUMN address_id SET DEFAULT nextval('address_address_id_seq'::regclass);


--
-- Name: category_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY categories ALTER COLUMN category_id SET DEFAULT nextval('categories_category_id_seq'::regclass);


--
-- Name: client_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY clients ALTER COLUMN client_id SET DEFAULT nextval('clients_client_id_seq'::regclass);


--
-- Name: currency_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY currencies ALTER COLUMN currency_id SET DEFAULT nextval('currencies_currency_id_seq'::regclass);


--
-- Name: discount_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY discounts ALTER COLUMN discount_id SET DEFAULT nextval('discounts_discount_id_seq'::regclass);


--
-- Name: menu_group_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY menu_groups ALTER COLUMN menu_group_id SET DEFAULT nextval('menu_groups_menu_group_id_seq'::regclass);


--
-- Name: menu_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY menus ALTER COLUMN menu_id SET DEFAULT nextval('menus_menu_id_seq'::regclass);


--
-- Name: order_details_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY order_details ALTER COLUMN order_details_id SET DEFAULT nextval('order_details_order_details_id_seq'::regclass);


--
-- Name: order_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY orders ALTER COLUMN order_id SET DEFAULT nextval('orders_order_id_seq'::regclass);


--
-- Name: phone_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY phones ALTER COLUMN phone_id SET DEFAULT nextval('phones_phone_id_seq'::regclass);


--
-- Name: restaurant_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY restaurants ALTER COLUMN restaurant_id SET DEFAULT nextval('restaurants_restaurant_id_seq'::regclass);


--
-- Name: street_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY street ALTER COLUMN street_id SET DEFAULT nextval('street_street_id_seq'::regclass);


--
-- Name: zone_details_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY zone_details ALTER COLUMN zone_details_id SET DEFAULT nextval('zone_details_zone_details_id_seq'::regclass);


--
-- Name: zone_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY zones ALTER COLUMN zone_id SET DEFAULT nextval('zones_zone_id_seq'::regclass);


--
-- Data for Name: address; Type: TABLE DATA; Schema: public; Owner: admin
--



--
-- Data for Name: categories; Type: TABLE DATA; Schema: public; Owner: admin
--

INSERT INTO categories VALUES ('Bar', '', false, 1122, 38);
INSERT INTO categories VALUES ('Pizza', '', false, 54564, 39);


--
-- Data for Name: clients; Type: TABLE DATA; Schema: public; Owner: admin
--



--
-- Data for Name: currencies; Type: TABLE DATA; Schema: public; Owner: admin
--

INSERT INTO currencies VALUES (92, 'adfad', 'eda', 13212312.31, false, false, 123123);
INSERT INTO currencies VALUES (93, '', '', 13131231.23, false, false, 0);
INSERT INTO currencies VALUES (94, 'wedaef', 'gha', 12412412.31, false, false, 125123);
INSERT INTO currencies VALUES (95, 'sfse', 'qew', 14123123.12, false, false, 124123);


--
-- Data for Name: discounts; Type: TABLE DATA; Schema: public; Owner: admin
--

INSERT INTO discounts VALUES (3, 'wq', 11, false);
INSERT INTO discounts VALUES (2, 'qwe', 15, false);
INSERT INTO discounts VALUES (1, 'asd', 16, false);


--
-- Data for Name: menu_groups; Type: TABLE DATA; Schema: public; Owner: admin
--

INSERT INTO menu_groups VALUES (1, 'Beer', NULL, false);


--
-- Data for Name: menus; Type: TABLE DATA; Schema: public; Owner: admin
--

INSERT INTO menus VALUES (1, 'Beer', '', 5000, 38, 1, false);


--
-- Data for Name: order_details; Type: TABLE DATA; Schema: public; Owner: admin
--



--
-- Data for Name: orders; Type: TABLE DATA; Schema: public; Owner: admin
--



--
-- Data for Name: phones; Type: TABLE DATA; Schema: public; Owner: admin
--



--
-- Data for Name: restaurants; Type: TABLE DATA; Schema: public; Owner: admin
--



--
-- Data for Name: street; Type: TABLE DATA; Schema: public; Owner: admin
--

INSERT INTO street VALUES (1, 'new street ', 23, 25);


--
-- Data for Name: zone_details; Type: TABLE DATA; Schema: public; Owner: admin
--



--
-- Data for Name: zones; Type: TABLE DATA; Schema: public; Owner: admin
--



--
-- Name: address_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY address
    ADD CONSTRAINT address_pkey PRIMARY KEY (address_id);


--
-- Name: clients_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY clients
    ADD CONSTRAINT clients_pkey PRIMARY KEY (client_id);


--
-- Name: currencies_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY currencies
    ADD CONSTRAINT currencies_pkey PRIMARY KEY (currency_id);


--
-- Name: discounts_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY discounts
    ADD CONSTRAINT discounts_pkey PRIMARY KEY (discount_id);


--
-- Name: menu_groups_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY menu_groups
    ADD CONSTRAINT menu_groups_pkey PRIMARY KEY (menu_group_id);


--
-- Name: menus_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY menus
    ADD CONSTRAINT menus_pkey PRIMARY KEY (menu_id);


--
-- Name: order_details_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY order_details
    ADD CONSTRAINT order_details_pkey PRIMARY KEY (order_details_id);


--
-- Name: orders_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY orders
    ADD CONSTRAINT orders_pkey PRIMARY KEY (order_id);


--
-- Name: phones_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY phones
    ADD CONSTRAINT phones_pkey PRIMARY KEY (phone_id);


--
-- Name: restaurants_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY restaurants
    ADD CONSTRAINT restaurants_pkey PRIMARY KEY (restaurant_id);


--
-- Name: street_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY street
    ADD CONSTRAINT street_pkey PRIMARY KEY (street_id);


--
-- Name: zone_details_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
--

ALTER TABLE ONLY zone_details
    ADD CONSTRAINT zone_details_pkey PRIMARY KEY (zone_details_id);


--
-- Name: zones_pkey; Type: CONSTRAINT; Schema: public; Owner: admin; Tablespace: 
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
-- Name: address; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE address FROM PUBLIC;
REVOKE ALL ON TABLE address FROM admin;
GRANT ALL ON TABLE address TO admin;
GRANT ALL ON TABLE address TO PUBLIC;
GRANT ALL ON TABLE address TO elpos;


--
-- Name: address_address_id_seq; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON SEQUENCE address_address_id_seq FROM PUBLIC;
REVOKE ALL ON SEQUENCE address_address_id_seq FROM admin;
GRANT ALL ON SEQUENCE address_address_id_seq TO admin;
GRANT ALL ON SEQUENCE address_address_id_seq TO PUBLIC;
GRANT ALL ON SEQUENCE address_address_id_seq TO elpos;


--
-- Name: categories; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE categories FROM PUBLIC;
REVOKE ALL ON TABLE categories FROM admin;
GRANT ALL ON TABLE categories TO admin;
GRANT ALL ON TABLE categories TO PUBLIC;
GRANT ALL ON TABLE categories TO elpos;


--
-- Name: clients; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE clients FROM PUBLIC;
REVOKE ALL ON TABLE clients FROM admin;
GRANT ALL ON TABLE clients TO admin;
GRANT ALL ON TABLE clients TO PUBLIC;
GRANT ALL ON TABLE clients TO elpos;


--
-- Name: clients_client_id_seq; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON SEQUENCE clients_client_id_seq FROM PUBLIC;
REVOKE ALL ON SEQUENCE clients_client_id_seq FROM admin;
GRANT ALL ON SEQUENCE clients_client_id_seq TO admin;
GRANT ALL ON SEQUENCE clients_client_id_seq TO PUBLIC;
GRANT ALL ON SEQUENCE clients_client_id_seq TO elpos;


--
-- Name: currencies; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE currencies FROM PUBLIC;
REVOKE ALL ON TABLE currencies FROM admin;
GRANT ALL ON TABLE currencies TO admin;
GRANT ALL ON TABLE currencies TO PUBLIC;
GRANT ALL ON TABLE currencies TO elpos;


--
-- Name: discounts; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE discounts FROM PUBLIC;
REVOKE ALL ON TABLE discounts FROM admin;
GRANT ALL ON TABLE discounts TO admin;
GRANT ALL ON TABLE discounts TO PUBLIC;
GRANT ALL ON TABLE discounts TO elpos;


--
-- Name: discounts_discount_id_seq; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON SEQUENCE discounts_discount_id_seq FROM PUBLIC;
REVOKE ALL ON SEQUENCE discounts_discount_id_seq FROM admin;
GRANT ALL ON SEQUENCE discounts_discount_id_seq TO admin;
GRANT ALL ON SEQUENCE discounts_discount_id_seq TO PUBLIC;
GRANT ALL ON SEQUENCE discounts_discount_id_seq TO elpos;


--
-- Name: menu_groups; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE menu_groups FROM PUBLIC;
REVOKE ALL ON TABLE menu_groups FROM admin;
GRANT ALL ON TABLE menu_groups TO admin;
GRANT ALL ON TABLE menu_groups TO PUBLIC;
GRANT ALL ON TABLE menu_groups TO elpos;


--
-- Name: menu_groups_menu_group_id_seq; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON SEQUENCE menu_groups_menu_group_id_seq FROM PUBLIC;
REVOKE ALL ON SEQUENCE menu_groups_menu_group_id_seq FROM admin;
GRANT ALL ON SEQUENCE menu_groups_menu_group_id_seq TO admin;
GRANT ALL ON SEQUENCE menu_groups_menu_group_id_seq TO PUBLIC;
GRANT ALL ON SEQUENCE menu_groups_menu_group_id_seq TO elpos;


--
-- Name: menus; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE menus FROM PUBLIC;
REVOKE ALL ON TABLE menus FROM admin;
GRANT ALL ON TABLE menus TO admin;
GRANT ALL ON TABLE menus TO PUBLIC;
GRANT ALL ON TABLE menus TO elpos;


--
-- Name: menus_menu_id_seq; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON SEQUENCE menus_menu_id_seq FROM PUBLIC;
REVOKE ALL ON SEQUENCE menus_menu_id_seq FROM admin;
GRANT ALL ON SEQUENCE menus_menu_id_seq TO admin;
GRANT ALL ON SEQUENCE menus_menu_id_seq TO PUBLIC;
GRANT ALL ON SEQUENCE menus_menu_id_seq TO elpos;


--
-- Name: order_details; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE order_details FROM PUBLIC;
REVOKE ALL ON TABLE order_details FROM admin;
GRANT ALL ON TABLE order_details TO admin;
GRANT ALL ON TABLE order_details TO PUBLIC;
GRANT ALL ON TABLE order_details TO elpos;
GRANT ALL ON TABLE order_details TO postgres;


--
-- Name: orders; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE orders FROM PUBLIC;
REVOKE ALL ON TABLE orders FROM admin;
GRANT ALL ON TABLE orders TO admin;
GRANT ALL ON TABLE orders TO PUBLIC;
GRANT ALL ON TABLE orders TO elpos;


--
-- Name: phones; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE phones FROM PUBLIC;
REVOKE ALL ON TABLE phones FROM admin;
GRANT ALL ON TABLE phones TO admin;
GRANT ALL ON TABLE phones TO PUBLIC;
GRANT ALL ON TABLE phones TO elpos;


--
-- Name: restaurants; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE restaurants FROM PUBLIC;
REVOKE ALL ON TABLE restaurants FROM admin;
GRANT ALL ON TABLE restaurants TO admin;
GRANT ALL ON TABLE restaurants TO PUBLIC;
GRANT ALL ON TABLE restaurants TO elpos;


--
-- Name: street; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE street FROM PUBLIC;
REVOKE ALL ON TABLE street FROM admin;
GRANT ALL ON TABLE street TO admin;
GRANT ALL ON TABLE street TO PUBLIC;
GRANT ALL ON TABLE street TO elpos;


--
-- Name: zone_details; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE zone_details FROM PUBLIC;
REVOKE ALL ON TABLE zone_details FROM admin;
GRANT ALL ON TABLE zone_details TO admin;
GRANT ALL ON TABLE zone_details TO PUBLIC;
GRANT ALL ON TABLE zone_details TO elpos;


--
-- Name: zones; Type: ACL; Schema: public; Owner: admin
--

REVOKE ALL ON TABLE zones FROM PUBLIC;
REVOKE ALL ON TABLE zones FROM admin;
GRANT ALL ON TABLE zones TO admin;
GRANT ALL ON TABLE zones TO PUBLIC;
GRANT ALL ON TABLE zones TO elpos;


--
-- PostgreSQL database dump complete
--

