--Destroy all tables in the order they were created:

begin transaction;

drop table entity_kinds cascade;
drop table entities cascade;
drop table emails cascade;
drop table email_phone_kinds cascade;
drop table locations cascade;
drop table phones cascade;
drop table quotes cascade;
drop table payment_types cascade;
drop table contacts cascade;
drop table areas cascade;
drop table works cascade;
drop table system_users cascade;
drop table products cascade;
drop table units_of_measurement cascade;
drop table product_kinds cascade;
drop table waterproofings cascade;
drop table work_kinds cascade;
drop table waterproofing_kinds cascade;
drop table entities_contacts cascade;
drop table locations_contacts cascade;
drop table areas_products cascade;
drop table works_products cascade;

commit;
