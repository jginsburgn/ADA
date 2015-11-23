
--We create all tables shown in the ERD from left to right and up to down.
--Attributes are added in the following order: intrinsic from left to right,
--and foreign keys in anti-clockwise direction starting from upper left.
--If attributes' names do not correspond to those of the ERD, a comment
--is appended to the end of the attribute specification stating their
--correspondence. In general, serial keys are added to attributes.
--Many to many caused tables are added to the end of the construction:

begin transaction;

create table entity_kinds (
    id serial primary key,
    kind text not null
);

create table entities (
    id serial primary key,
    rfc text unique not null,
    entity_name text unique not null,
    kind integer not null
);

create table emails (
    id serial primary key,
    address text unique not null,
    contact integer,
    kind integer not null
);

create table email_phone_kinds (
    id serial primary key,
    kind text not null
);

create table locations (
    id serial primary key,
    address text not null,
    entity integer not null
);

create table phones (
    id serial primary key,
    area_code text not null,
    number text not null,
    phone_extension text,
    contact integer,
    kind integer not null
);

create table quotes (
    id serial primary key, -- this is the identifier
    description text,
    tax_percentage decimal not null,
    estimated_work_days integer not null,
    pending_date date not null,
    working_date date,
    completed_date date,
    percentage_begin decimal, --Begin
    percentage_middle decimal, --Middle
    percentage_end decimal, --End
    installments integer, --Number of Installments
    a_location integer not null, -- This is a foreign key to locations
    payment_type int not null --This is a foreign key to payment_types
);

create table payment_types (
    id serial primary key,
    a_type text not null unique
);

create table contacts (
    id serial primary key,
    contact_name text not null, --Name
    surnames text
);

create table areas (
    id serial primary key,
    description text not null,
    measure decimal not null,
    unit_price decimal not null,
    a_work integer not null -- This is a foreign key to works
);

create table works (
    id serial primary key,
    description text not null,
    unit_of_measurement integer not null,
    kind integer not null,
    a_quote integer not null --This is a foreign key to quotes
);

create table system_users (
    id serial primary key,
    username text unique,
    a_password text, -- Password
    privilege decimal not null-- The less the greatest
);

create table products (
    id serial primary key,
    product_name text not null, --Name
    brand text not null,
    description text,
    discount decimal,
    price decimal not null,
    amount_of_content decimal not null,
    entity integer not null,
    waterproofing integer,
    kind integer not null,
    unit_of_measurement integer not null
);

create table units_of_measurement (
    id serial primary key,
    unit text not null
);

create table product_kinds (
    id serial primary key,
    kind text not null
);

create table waterproofings (
    id serial primary key,
    warranty integer,
    width decimal,
    color text not null,
    product integer not null,
    kind integer not null
);

create table work_kinds (
    id serial primary key,
    kind text not null
);

create table waterproofing_kinds (
    id serial primary key,
    kind text not null
);

--Many to many relations caused tables creation:

create table entities_contacts (
    id serial primary key,
    entity integer not null,
    contact integer not null
);

create table locations_contacts (
    id serial primary key,
    a_location integer not null, --This is a foreign key to locations
    contact integer not null
);

create table areas_products (
    id serial primary key,
    area integer not null,
    product integer not null
);

create table works_products (
    id serial primary key,
    a_work integer not null, --This is a foreign key to works
    product integer not null
);

--Foreign key additions:

alter table entities
add foreign key (kind)
references entity_kinds(id);

alter table emails
add foreign key (contact)
references contacts(id);

alter table emails
add foreign key (kind)
references email_phone_kinds(id);

alter table locations
add foreign key (entity)
references entities(id);

alter table phones
add foreign key (contact)
references contacts(id);

alter table phones
add foreign key (kind)
references email_phone_kinds(id);

alter table quotes
add foreign key (a_location)
references locations(id);

alter table quotes
add foreign key (payment_type)
references payment_types(id);

alter table areas
add foreign key (a_work)
references works(id);

alter table works
add foreign key (unit_of_measurement)
references units_of_measurement(id);

alter table works
add foreign key (kind)
references work_kinds(id);

alter table works
add foreign key (a_quote)
references quotes(id);

alter table products
add foreign key (entity)
references entities(id);

alter table products
add foreign key (waterproofing)
references waterproofings(id);

alter table products
add foreign key (kind)
references product_kinds(id);

alter table products
add foreign key (unit_of_measurement)
references units_of_measurement(id);

alter table waterproofings
add foreign key (kind)
references waterproofing_kinds(id);

alter table entities_contacts
add foreign key (entity)
references entities(id);

alter table entities_contacts
add foreign key (contact)
references contacts(id);

alter table locations_contacts
add foreign key (a_location)
references locations(id);

alter table locations_contacts
add foreign key (contact)
references contacts(id);

alter table areas_products
add foreign key (area)
references areas(id);

alter table areas_products
add foreign key (product)
references products(id);

alter table works_products
add foreign key (a_work)
references works(id);

alter table works_products
add foreign key (product)
references products(id);

commit;
