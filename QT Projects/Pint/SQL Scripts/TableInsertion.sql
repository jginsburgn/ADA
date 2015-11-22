-- Insert enumeration values:

begin transaction;

insert into email_phone_kinds values (1, 'Home');
insert into email_phone_kinds values (2, 'Mobile');
insert into email_phone_kinds values (3, 'Work');

insert into entity_kinds values (1, 'Customer');
insert into entity_kinds values (2, 'Supplier');

insert into product_kinds values (1, 'Waterproof');
insert into product_kinds values (2, 'Paint');
insert into product_kinds values (3, 'Primer');
insert into product_kinds values (4, 'Cement');
insert into product_kinds values (5, 'Sand');
insert into product_kinds values (6, 'Acid');
insert into product_kinds values (7, 'Tool');
insert into product_kinds values (8, 'Insulator');

insert into units_of_measurement values (1, 'Square Meters');
insert into units_of_measurement values (2, 'Linear Meters');
insert into units_of_measurement values (3, 'Gallons');
insert into units_of_measurement values (4, 'Liters');
insert into units_of_measurement values (5, 'Generic');

insert into waterproofing_kinds values (1, 'Acrylic');
insert into waterproofing_kinds values (2, 'Epoxy');
insert into waterproofing_kinds values (3, 'Plastic');
insert into waterproofing_kinds values (4, 'Prefab');

insert into work_kinds values (1, 'Carpentry');
insert into work_kinds values (2, 'Waterproofing');
insert into work_kinds values (3, 'Painting');
insert into work_kinds values (4, 'Masonry');

insert into payment_types values (1, 'Cash');
insert into payment_types values (2, 'Credit Card');

--For testing purposes:
insert into system_users (username, a_password, privilege) values
('', '', 0), ('jgn1055', '1234', 0);

commit;
