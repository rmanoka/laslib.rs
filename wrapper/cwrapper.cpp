#include "cwrapper.h"
#include "lib.hpp"
#ifdef __cplusplus
extern "C"{
#endif


// LASvlr_lastiling
unsigned int *LASvlr_lastiling_field_level(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASvlr_lastiling *>(self)->level);
}
unsigned int *LASvlr_lastiling_field_level_index(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASvlr_lastiling *>(self)->level_index);
}
float *LASvlr_lastiling_field_min_x(void *self) {
	return reinterpret_cast<float *>(
		&reinterpret_cast<LASvlr_lastiling *>(self)->min_x);
}
float *LASvlr_lastiling_field_max_x(void *self) {
	return reinterpret_cast<float *>(
		&reinterpret_cast<LASvlr_lastiling *>(self)->max_x);
}
float *LASvlr_lastiling_field_min_y(void *self) {
	return reinterpret_cast<float *>(
		&reinterpret_cast<LASvlr_lastiling *>(self)->min_y);
}
float *LASvlr_lastiling_field_max_y(void *self) {
	return reinterpret_cast<float *>(
		&reinterpret_cast<LASvlr_lastiling *>(self)->max_y);
}
void *LASvlr_lastiling_create(){
  return reinterpret_cast<void *>(new LASvlr_lastiling());
}


// LASvlr_lasoriginal
long long *LASvlr_lasoriginal_field_number_of_point_records(void *self) {
	return reinterpret_cast<long long *>(
		&reinterpret_cast<LASvlr_lasoriginal *>(self)->number_of_point_records);
}
void *LASvlr_lasoriginal_field_number_of_points_by_return(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASvlr_lasoriginal *>(self)->number_of_points_by_return);
}
double *LASvlr_lasoriginal_field_max_x(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASvlr_lasoriginal *>(self)->max_x);
}
double *LASvlr_lasoriginal_field_min_x(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASvlr_lasoriginal *>(self)->min_x);
}
double *LASvlr_lasoriginal_field_max_y(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASvlr_lasoriginal *>(self)->max_y);
}
double *LASvlr_lasoriginal_field_min_y(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASvlr_lasoriginal *>(self)->min_y);
}
double *LASvlr_lasoriginal_field_max_z(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASvlr_lasoriginal *>(self)->max_z);
}
double *LASvlr_lasoriginal_field_min_z(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASvlr_lasoriginal *>(self)->min_z);
}
long long *LASvlr_lasoriginal_field_position(void *self) {
	return reinterpret_cast<long long *>(
		&reinterpret_cast<LASvlr_lasoriginal *>(self)->position);
}
void *LASvlr_lasoriginal_create(){
  return reinterpret_cast<void *>(new LASvlr_lasoriginal());
}


// LASitem
void *LASitem_field_type(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASitem *>(self)->type);
}
unsigned short *LASitem_field_size(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASitem *>(self)->size);
}
unsigned short *LASitem_field_version(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASitem *>(self)->version);
}
const void * LASitem_get_name(void *self){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASitem *>(self)->get_name());}


// LASzip
bool LASzip_check_compressor(void *self, const unsigned short compressor){
  return reinterpret_cast<LASzip *>(self)->check_compressor(compressor);}
bool LASzip_check_coder(void *self, const unsigned short coder){
  return reinterpret_cast<LASzip *>(self)->check_coder(coder);}
bool LASzip_check_item(void *self, const void * item){
  return reinterpret_cast<LASzip *>(self)->check_item(
	reinterpret_cast<const LASitem *>(item));}
bool LASzip_check_items(void *self, const unsigned short num_items, const void * items, const unsigned short point_size){
  return reinterpret_cast<LASzip *>(self)->check_items(num_items,
	reinterpret_cast<const LASitem *>(items), point_size);}
bool LASzip_check(void *self, const unsigned short point_size){
  return reinterpret_cast<LASzip *>(self)->check(point_size);}
bool LASzip_setup(void *self, void * num_items, void * items, const unsigned char point_type, const unsigned short point_size, const unsigned short compressor){
  return reinterpret_cast<LASzip *>(self)->setup(
	reinterpret_cast<unsigned short *>(num_items),
	reinterpret_cast<LASitem **>(items), point_type, point_size, compressor);}
bool LASzip_is_standard(void *self, const unsigned short num_items, const void * items, void * point_type, void * record_length){
  return reinterpret_cast<LASzip *>(self)->is_standard(num_items,
	reinterpret_cast<const LASitem *>(items),
	reinterpret_cast<unsigned char *>(point_type),
	reinterpret_cast<unsigned short *>(record_length));}
bool LASzip_is_standard_1(void *self, void * point_type, void * record_length){
  return reinterpret_cast<LASzip *>(self)->is_standard(
	reinterpret_cast<unsigned char *>(point_type),
	reinterpret_cast<unsigned short *>(record_length));}
void *LASzip_field_bytes(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASzip *>(self)->bytes);
}
bool LASzip_unpack(void *self, const void * bytes, const int num){
  return reinterpret_cast<LASzip *>(self)->unpack(
	reinterpret_cast<const unsigned char *>(bytes), num);}
bool LASzip_request_compatibility_mode(void *self, const unsigned short requested_compatibility_mode){
  return reinterpret_cast<LASzip *>(self)->request_compatibility_mode(requested_compatibility_mode);}
bool LASzip_setup_1(void *self, const unsigned char point_type, const unsigned short point_size, const unsigned short compressor){
  return reinterpret_cast<LASzip *>(self)->setup(point_type, point_size, compressor);}
bool LASzip_setup_2(void *self, const unsigned short num_items, const void * items, const unsigned short compressor){
  return reinterpret_cast<LASzip *>(self)->setup(num_items,
	reinterpret_cast<const LASitem *>(items), compressor);}
bool LASzip_set_chunk_size(void *self, const unsigned int chunk_size){
  return reinterpret_cast<LASzip *>(self)->set_chunk_size(chunk_size);}
bool LASzip_request_version(void *self, const unsigned short requested_version){
  return reinterpret_cast<LASzip *>(self)->request_version(requested_version);}
const void * LASzip_get_error(void *self){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASzip *>(self)->get_error());}
unsigned short *LASzip_field_compressor(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASzip *>(self)->compressor);
}
unsigned short *LASzip_field_coder(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASzip *>(self)->coder);
}
unsigned char *LASzip_field_version_major(void *self) {
	return reinterpret_cast<unsigned char *>(
		&reinterpret_cast<LASzip *>(self)->version_major);
}
unsigned char *LASzip_field_version_minor(void *self) {
	return reinterpret_cast<unsigned char *>(
		&reinterpret_cast<LASzip *>(self)->version_minor);
}
unsigned short *LASzip_field_version_revision(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASzip *>(self)->version_revision);
}
unsigned int *LASzip_field_options(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASzip *>(self)->options);
}
unsigned int *LASzip_field_chunk_size(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASzip *>(self)->chunk_size);
}
long long *LASzip_field_number_of_special_evlrs(void *self) {
	return reinterpret_cast<long long *>(
		&reinterpret_cast<LASzip *>(self)->number_of_special_evlrs);
}
long long *LASzip_field_offset_to_special_evlrs(void *self) {
	return reinterpret_cast<long long *>(
		&reinterpret_cast<LASzip *>(self)->offset_to_special_evlrs);
}
unsigned short *LASzip_field_num_items(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASzip *>(self)->num_items);
}
void *LASzip_field_items(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASzip *>(self)->items);
}
void *LASzip_create(){
  return reinterpret_cast<void *>(new LASzip());
}
void LASzip_destroy(void *self){
  delete reinterpret_cast<LASzip*>(self);
}


// LASquantizer
double *LASquantizer_field_x_scale_factor(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASquantizer *>(self)->x_scale_factor);
}
double *LASquantizer_field_y_scale_factor(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASquantizer *>(self)->y_scale_factor);
}
double *LASquantizer_field_z_scale_factor(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASquantizer *>(self)->z_scale_factor);
}
double *LASquantizer_field_x_offset(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASquantizer *>(self)->x_offset);
}
double *LASquantizer_field_y_offset(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASquantizer *>(self)->y_offset);
}
double *LASquantizer_field_z_offset(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASquantizer *>(self)->z_offset);
}
double LASquantizer_get_x(void *self, const int X){
  return reinterpret_cast<const LASquantizer *>(self)->get_x(X);}
double LASquantizer_get_y(void *self, const int Y){
  return reinterpret_cast<const LASquantizer *>(self)->get_y(Y);}
double LASquantizer_get_z(void *self, const int Z){
  return reinterpret_cast<const LASquantizer *>(self)->get_z(Z);}
long long LASquantizer_get_X(void *self, const double x){
  return reinterpret_cast<const LASquantizer *>(self)->get_X(x);}
long long LASquantizer_get_Y(void *self, const double y){
  return reinterpret_cast<const LASquantizer *>(self)->get_Y(y);}
long long LASquantizer_get_Z(void *self, const double z){
  return reinterpret_cast<const LASquantizer *>(self)->get_Z(z);}
void *LASquantizer_create(){
  return reinterpret_cast<void *>(new LASquantizer());
}


// LASattribute
void *LASattribute_field_reserved(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattribute *>(self)->reserved);
}
unsigned char *LASattribute_field_data_type(void *self) {
	return reinterpret_cast<unsigned char *>(
		&reinterpret_cast<LASattribute *>(self)->data_type);
}
unsigned char *LASattribute_field_options(void *self) {
	return reinterpret_cast<unsigned char *>(
		&reinterpret_cast<LASattribute *>(self)->options);
}
void *LASattribute_field_name(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattribute *>(self)->name);
}
void *LASattribute_field_unused(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattribute *>(self)->unused);
}
void *LASattribute_field_no_data(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattribute *>(self)->no_data);
}
void *LASattribute_field_min(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattribute *>(self)->min);
}
void *LASattribute_field_max(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattribute *>(self)->max);
}
void *LASattribute_field_scale(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattribute *>(self)->scale);
}
void *LASattribute_field_offset(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattribute *>(self)->offset);
}
void *LASattribute_field_description(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattribute *>(self)->description);
}
void *LASattribute_create(unsigned char size){
  return reinterpret_cast<void *>(new LASattribute(size));
}
void *LASattribute_create_1(unsigned int type, const void * name, const void * description){
  return reinterpret_cast<void *>(new LASattribute(type,
	reinterpret_cast<const char *>(name),
	reinterpret_cast<const char *>(description)));
}
bool LASattribute_set_no_data(void *self, unsigned char no_data){
  return reinterpret_cast<LASattribute *>(self)->set_no_data(no_data);}
bool LASattribute_set_no_data_1(void *self, char no_data){
  return reinterpret_cast<LASattribute *>(self)->set_no_data(no_data);}
bool LASattribute_set_no_data_2(void *self, unsigned short no_data){
  return reinterpret_cast<LASattribute *>(self)->set_no_data(no_data);}
bool LASattribute_set_no_data_3(void *self, short no_data){
  return reinterpret_cast<LASattribute *>(self)->set_no_data(no_data);}
bool LASattribute_set_no_data_4(void *self, unsigned int no_data){
  return reinterpret_cast<LASattribute *>(self)->set_no_data(no_data);}
bool LASattribute_set_no_data_5(void *self, int no_data){
  return reinterpret_cast<LASattribute *>(self)->set_no_data(no_data);}
bool LASattribute_set_no_data_6(void *self, unsigned long long no_data){
  return reinterpret_cast<LASattribute *>(self)->set_no_data(no_data);}
bool LASattribute_set_no_data_7(void *self, long long no_data){
  return reinterpret_cast<LASattribute *>(self)->set_no_data(no_data);}
bool LASattribute_set_no_data_8(void *self, float no_data){
  return reinterpret_cast<LASattribute *>(self)->set_no_data(no_data);}
bool LASattribute_set_no_data_9(void *self, double no_data){
  return reinterpret_cast<LASattribute *>(self)->set_no_data(no_data);}
void LASattribute_set_min(void *self, void * min){
  reinterpret_cast<LASattribute *>(self)->set_min(
	reinterpret_cast<unsigned char *>(min));}
void LASattribute_update_min(void *self, void * min){
  reinterpret_cast<LASattribute *>(self)->update_min(
	reinterpret_cast<unsigned char *>(min));}
bool LASattribute_set_min_1(void *self, unsigned char min){
  return reinterpret_cast<LASattribute *>(self)->set_min(min);}
bool LASattribute_set_min_2(void *self, char min){
  return reinterpret_cast<LASattribute *>(self)->set_min(min);}
bool LASattribute_set_min_3(void *self, unsigned short min){
  return reinterpret_cast<LASattribute *>(self)->set_min(min);}
bool LASattribute_set_min_4(void *self, short min){
  return reinterpret_cast<LASattribute *>(self)->set_min(min);}
bool LASattribute_set_min_5(void *self, unsigned int min){
  return reinterpret_cast<LASattribute *>(self)->set_min(min);}
bool LASattribute_set_min_6(void *self, int min){
  return reinterpret_cast<LASattribute *>(self)->set_min(min);}
bool LASattribute_set_min_7(void *self, unsigned long long min){
  return reinterpret_cast<LASattribute *>(self)->set_min(min);}
bool LASattribute_set_min_8(void *self, long long min){
  return reinterpret_cast<LASattribute *>(self)->set_min(min);}
bool LASattribute_set_min_9(void *self, float min){
  return reinterpret_cast<LASattribute *>(self)->set_min(min);}
bool LASattribute_set_min_10(void *self, double min){
  return reinterpret_cast<LASattribute *>(self)->set_min(min);}
void LASattribute_set_max(void *self, void * max){
  reinterpret_cast<LASattribute *>(self)->set_max(
	reinterpret_cast<unsigned char *>(max));}
void LASattribute_update_max(void *self, void * max){
  reinterpret_cast<LASattribute *>(self)->update_max(
	reinterpret_cast<unsigned char *>(max));}
bool LASattribute_set_max_1(void *self, unsigned char max){
  return reinterpret_cast<LASattribute *>(self)->set_max(max);}
bool LASattribute_set_max_2(void *self, char max){
  return reinterpret_cast<LASattribute *>(self)->set_max(max);}
bool LASattribute_set_max_3(void *self, unsigned short max){
  return reinterpret_cast<LASattribute *>(self)->set_max(max);}
bool LASattribute_set_max_4(void *self, short max){
  return reinterpret_cast<LASattribute *>(self)->set_max(max);}
bool LASattribute_set_max_5(void *self, unsigned int max){
  return reinterpret_cast<LASattribute *>(self)->set_max(max);}
bool LASattribute_set_max_6(void *self, int max){
  return reinterpret_cast<LASattribute *>(self)->set_max(max);}
bool LASattribute_set_max_7(void *self, unsigned long long max){
  return reinterpret_cast<LASattribute *>(self)->set_max(max);}
bool LASattribute_set_max_8(void *self, long long max){
  return reinterpret_cast<LASattribute *>(self)->set_max(max);}
bool LASattribute_set_max_9(void *self, float max){
  return reinterpret_cast<LASattribute *>(self)->set_max(max);}
bool LASattribute_set_max_10(void *self, double max){
  return reinterpret_cast<LASattribute *>(self)->set_max(max);}
bool LASattribute_set_scale(void *self, double scale){
  return reinterpret_cast<LASattribute *>(self)->set_scale(scale);}
bool LASattribute_set_offset(void *self, double offset){
  return reinterpret_cast<LASattribute *>(self)->set_offset(offset);}
bool LASattribute_unset_scale(void *self){
  return reinterpret_cast<LASattribute *>(self)->unset_scale();}
bool LASattribute_unset_offset(void *self){
  return reinterpret_cast<LASattribute *>(self)->unset_offset();}
bool LASattribute_has_no_data(void *self){
  return reinterpret_cast<const LASattribute *>(self)->has_no_data();}
bool LASattribute_has_min(void *self){
  return reinterpret_cast<const LASattribute *>(self)->has_min();}
bool LASattribute_has_max(void *self){
  return reinterpret_cast<const LASattribute *>(self)->has_max();}
bool LASattribute_has_scale(void *self){
  return reinterpret_cast<const LASattribute *>(self)->has_scale();}
bool LASattribute_has_offset(void *self){
  return reinterpret_cast<const LASattribute *>(self)->has_offset();}
unsigned int LASattribute_get_size(void *self){
  return reinterpret_cast<const LASattribute *>(self)->get_size();}
double LASattribute_get_value_as_float(void *self, void * pointer){
  return reinterpret_cast<const LASattribute *>(self)->get_value_as_float(
	reinterpret_cast<unsigned char *>(pointer));}
void LASattribute_set_value_as_float(void *self, void * pointer, double value){
  reinterpret_cast<const LASattribute *>(self)->set_value_as_float(
	reinterpret_cast<unsigned char *>(pointer), value);}


// LASattributer
bool *LASattributer_field_attributes_linked(void *self) {
	return reinterpret_cast<bool *>(
		&reinterpret_cast<LASattributer *>(self)->attributes_linked);
}
int *LASattributer_field_number_attributes(void *self) {
	return reinterpret_cast<int *>(
		&reinterpret_cast<LASattributer *>(self)->number_attributes);
}
void *LASattributer_field_attributes(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattributer *>(self)->attributes);
}
void *LASattributer_field_attribute_starts(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattributer *>(self)->attribute_starts);
}
void *LASattributer_field_attribute_sizes(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASattributer *>(self)->attribute_sizes);
}
void *LASattributer_create(){
  return reinterpret_cast<void *>(new LASattributer());
}
void LASattributer_destroy(void *self){
  delete reinterpret_cast<LASattributer*>(self);
}
void LASattributer_clean_attributes(void *self){
  reinterpret_cast<LASattributer *>(self)->clean_attributes();}
bool LASattributer_init_attributes(void *self, unsigned int number_attributes, void * attributes){
  return reinterpret_cast<LASattributer *>(self)->init_attributes(number_attributes,
	reinterpret_cast<LASattribute *>(attributes));}
short LASattributer_get_attributes_size(void *self){
  return reinterpret_cast<const LASattributer *>(self)->get_attributes_size();}
int LASattributer_get_attribute_index(void *self, const void * name){
  return reinterpret_cast<const LASattributer *>(self)->get_attribute_index(
	reinterpret_cast<const char *>(name));}
int LASattributer_get_attribute_start(void *self, const void * name){
  return reinterpret_cast<const LASattributer *>(self)->get_attribute_start(
	reinterpret_cast<const char *>(name));}
int LASattributer_get_attribute_start_1(void *self, int index){
  return reinterpret_cast<const LASattributer *>(self)->get_attribute_start(index);}
int LASattributer_get_attribute_size(void *self, int index){
  return reinterpret_cast<const LASattributer *>(self)->get_attribute_size(index);}
const void * LASattributer_get_attribute_name(void *self, int index){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASattributer *>(self)->get_attribute_name(index));}
bool LASattributer_remove_attribute(void *self, int index){
  return reinterpret_cast<LASattributer *>(self)->remove_attribute(index);}
bool LASattributer_remove_attribute_1(void *self, const void * name){
  return reinterpret_cast<LASattributer *>(self)->remove_attribute(
	reinterpret_cast<const char *>(name));}


// LASwavepacket
void *LASwavepacket_create(){
  return reinterpret_cast<void *>(new LASwavepacket());
}
void LASwavepacket_zero(void *self){
  reinterpret_cast<LASwavepacket *>(self)->zero();}
unsigned char LASwavepacket_getIndex(void *self){
  return reinterpret_cast<const LASwavepacket *>(self)->getIndex();}
unsigned long long LASwavepacket_getOffset(void *self){
  return reinterpret_cast<const LASwavepacket *>(self)->getOffset();}
unsigned int LASwavepacket_getSize(void *self){
  return reinterpret_cast<const LASwavepacket *>(self)->getSize();}
float LASwavepacket_getLocation(void *self){
  return reinterpret_cast<const LASwavepacket *>(self)->getLocation();}
float LASwavepacket_getXt(void *self){
  return reinterpret_cast<const LASwavepacket *>(self)->getXt();}
float LASwavepacket_getYt(void *self){
  return reinterpret_cast<const LASwavepacket *>(self)->getYt();}
float LASwavepacket_getZt(void *self){
  return reinterpret_cast<const LASwavepacket *>(self)->getZt();}
void LASwavepacket_setIndex(void *self, unsigned char index){
  reinterpret_cast<LASwavepacket *>(self)->setIndex(index);}
void LASwavepacket_setOffset(void *self, unsigned long long offset){
  reinterpret_cast<LASwavepacket *>(self)->setOffset(offset);}
void LASwavepacket_setSize(void *self, unsigned int size){
  reinterpret_cast<LASwavepacket *>(self)->setSize(size);}
void LASwavepacket_setLocation(void *self, float location){
  reinterpret_cast<LASwavepacket *>(self)->setLocation(location);}
void LASwavepacket_setXt(void *self, float xt){
  reinterpret_cast<LASwavepacket *>(self)->setXt(xt);}
void LASwavepacket_setYt(void *self, float yt){
  reinterpret_cast<LASwavepacket *>(self)->setYt(yt);}
void LASwavepacket_setZt(void *self, float zt){
  reinterpret_cast<LASwavepacket *>(self)->setZt(zt);}
void LASwavepacket_flipDirection(void *self){
  reinterpret_cast<LASwavepacket *>(self)->flipDirection();}


// LASpoint
int *LASpoint_field_X(void *self) {
	return reinterpret_cast<int *>(
		&reinterpret_cast<LASpoint *>(self)->X);
}
int *LASpoint_field_Y(void *self) {
	return reinterpret_cast<int *>(
		&reinterpret_cast<LASpoint *>(self)->Y);
}
int *LASpoint_field_Z(void *self) {
	return reinterpret_cast<int *>(
		&reinterpret_cast<LASpoint *>(self)->Z);
}
unsigned short *LASpoint_field_intensity(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASpoint *>(self)->intensity);
}
char *LASpoint_field_scan_angle_rank(void *self) {
	return reinterpret_cast<char *>(
		&reinterpret_cast<LASpoint *>(self)->scan_angle_rank);
}
unsigned char *LASpoint_field_user_data(void *self) {
	return reinterpret_cast<unsigned char *>(
		&reinterpret_cast<LASpoint *>(self)->user_data);
}
unsigned short *LASpoint_field_point_source_ID(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASpoint *>(self)->point_source_ID);
}
short *LASpoint_field_extended_scan_angle(void *self) {
	return reinterpret_cast<short *>(
		&reinterpret_cast<LASpoint *>(self)->extended_scan_angle);
}
unsigned char *LASpoint_field_extended_classification(void *self) {
	return reinterpret_cast<unsigned char *>(
		&reinterpret_cast<LASpoint *>(self)->extended_classification);
}
unsigned char *LASpoint_field_deleted_flag(void *self) {
	return reinterpret_cast<unsigned char *>(
		&reinterpret_cast<LASpoint *>(self)->deleted_flag);
}
void *LASpoint_field_dummy(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASpoint *>(self)->dummy);
}
bool *LASpoint_field_gps_time_change(void *self) {
	return reinterpret_cast<bool *>(
		&reinterpret_cast<LASpoint *>(self)->gps_time_change);
}
double *LASpoint_field_gps_time(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASpoint *>(self)->gps_time);
}
void *LASpoint_field_rgb(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASpoint *>(self)->rgb);
}
void *LASpoint_field_wavepacket(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASpoint *>(self)->wavepacket);
}
void *LASpoint_field_extra_bytes(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASpoint *>(self)->extra_bytes);
}
void *LASpoint_field_quantizer(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASpoint *>(self)->quantizer);
}
void *LASpoint_field_coordinates(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASpoint *>(self)->coordinates);
}
void *LASpoint_field_attributer(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASpoint *>(self)->attributer);
}
void *LASpoint_field_point(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASpoint *>(self)->point);
}
bool *LASpoint_field_have_gps_time(void *self) {
	return reinterpret_cast<bool *>(
		&reinterpret_cast<LASpoint *>(self)->have_gps_time);
}
bool *LASpoint_field_have_rgb(void *self) {
	return reinterpret_cast<bool *>(
		&reinterpret_cast<LASpoint *>(self)->have_rgb);
}
bool *LASpoint_field_have_nir(void *self) {
	return reinterpret_cast<bool *>(
		&reinterpret_cast<LASpoint *>(self)->have_nir);
}
bool *LASpoint_field_have_wavepacket(void *self) {
	return reinterpret_cast<bool *>(
		&reinterpret_cast<LASpoint *>(self)->have_wavepacket);
}
int *LASpoint_field_extra_bytes_number(void *self) {
	return reinterpret_cast<int *>(
		&reinterpret_cast<LASpoint *>(self)->extra_bytes_number);
}
unsigned int *LASpoint_field_total_point_size(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASpoint *>(self)->total_point_size);
}
unsigned short *LASpoint_field_num_items(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASpoint *>(self)->num_items);
}
void *LASpoint_field_items(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASpoint *>(self)->items);
}
void LASpoint_copy_to(void *self, void * buffer){
  reinterpret_cast<const LASpoint *>(self)->copy_to(
	reinterpret_cast<unsigned char *>(buffer));}
void LASpoint_copy_from(void *self, const void * buffer){
  reinterpret_cast<LASpoint *>(self)->copy_from(
	reinterpret_cast<const unsigned char *>(buffer));}
bool LASpoint_init(void *self, const void * quantizer, const unsigned char point_type, const unsigned short point_size, const void * attributer){
  return reinterpret_cast<LASpoint *>(self)->init(
	reinterpret_cast<const LASquantizer *>(quantizer), point_type, point_size,
	reinterpret_cast<const LASattributer *>(attributer));}
bool LASpoint_init_1(void *self, const void * quantizer, const unsigned int num_items, const void * items, const void * attributer){
  return reinterpret_cast<LASpoint *>(self)->init(
	reinterpret_cast<const LASquantizer *>(quantizer), num_items,
	reinterpret_cast<const LASitem *>(items),
	reinterpret_cast<const LASattributer *>(attributer));}
bool LASpoint_inside_rectangle(void *self, const double r_min_x, const double r_min_y, const double r_max_x, const double r_max_y){
  return reinterpret_cast<const LASpoint *>(self)->inside_rectangle(r_min_x, r_min_y, r_max_x, r_max_y);}
bool LASpoint_inside_tile(void *self, const float ll_x, const float ll_y, const float ur_x, const float ur_y){
  return reinterpret_cast<const LASpoint *>(self)->inside_tile(ll_x, ll_y, ur_x, ur_y);}
bool LASpoint_inside_circle(void *self, const double center_x, const double center_y, double squared_radius){
  return reinterpret_cast<const LASpoint *>(self)->inside_circle(center_x, center_y, squared_radius);}
bool LASpoint_inside_box(void *self, const double min_x, const double min_y, const double min_z, const double max_x, const double max_y, const double max_z){
  return reinterpret_cast<const LASpoint *>(self)->inside_box(min_x, min_y, min_z, max_x, max_y, max_z);}
bool LASpoint_inside_bounding_box(void *self, const double min_x, const double min_y, const double min_z, const double max_x, const double max_y, const double max_z){
  return reinterpret_cast<const LASpoint *>(self)->inside_bounding_box(min_x, min_y, min_z, max_x, max_y, max_z);}
bool LASpoint_is_zero(void *self){
  return reinterpret_cast<const LASpoint *>(self)->is_zero();}
void LASpoint_zero(void *self){
  reinterpret_cast<LASpoint *>(self)->zero();}
void LASpoint_clean(void *self){
  reinterpret_cast<LASpoint *>(self)->clean();}
void *LASpoint_create(){
  return reinterpret_cast<void *>(new LASpoint());
}
bool LASpoint_is_first(void *self){
  return reinterpret_cast<const LASpoint *>(self)->is_first();}
bool LASpoint_is_intermediate(void *self){
  return reinterpret_cast<const LASpoint *>(self)->is_intermediate();}
bool LASpoint_is_last(void *self){
  return reinterpret_cast<const LASpoint *>(self)->is_last();}
bool LASpoint_is_single(void *self){
  return reinterpret_cast<const LASpoint *>(self)->is_single();}
bool LASpoint_is_first_of_many(void *self){
  return reinterpret_cast<const LASpoint *>(self)->is_first_of_many();}
bool LASpoint_is_last_of_many(void *self){
  return reinterpret_cast<const LASpoint *>(self)->is_last_of_many();}
int LASpoint_get_X(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_X();}
int LASpoint_get_Y(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_Y();}
int LASpoint_get_Z(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_Z();}
unsigned short LASpoint_get_intensity(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_intensity();}
unsigned char LASpoint_get_return_number(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_return_number();}
unsigned char LASpoint_get_number_of_returns(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_number_of_returns();}
unsigned char LASpoint_get_scan_direction_flag(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_scan_direction_flag();}
unsigned char LASpoint_get_edge_of_flight_line(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_edge_of_flight_line();}
unsigned char LASpoint_get_classification(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_classification();}
unsigned char LASpoint_get_synthetic_flag(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_synthetic_flag();}
unsigned char LASpoint_get_keypoint_flag(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_keypoint_flag();}
unsigned char LASpoint_get_withheld_flag(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_withheld_flag();}
char LASpoint_get_scan_angle_rank(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_scan_angle_rank();}
unsigned char LASpoint_get_user_data(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_user_data();}
unsigned short LASpoint_get_point_source_ID(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_point_source_ID();}
unsigned char LASpoint_get_deleted_flag(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_deleted_flag();}
double LASpoint_get_gps_time(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_gps_time();}
const void * LASpoint_get_RGB(void *self){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASpoint *>(self)->get_RGB());}
const void * LASpoint_get_RGBI(void *self){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASpoint *>(self)->get_RGBI());}
unsigned short LASpoint_get_RGBI_1(void *self, const unsigned int band){
  return reinterpret_cast<const LASpoint *>(self)->get_RGBI(band);}
unsigned short LASpoint_get_R(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_R();}
unsigned short LASpoint_get_G(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_G();}
unsigned short LASpoint_get_B(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_B();}
unsigned short LASpoint_get_I(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_I();}
unsigned short LASpoint_get_NIR(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_NIR();}
void LASpoint_set_X(void *self, const int X){
  reinterpret_cast<LASpoint *>(self)->set_X(X);}
void LASpoint_set_Y(void *self, const int Y){
  reinterpret_cast<LASpoint *>(self)->set_Y(Y);}
void LASpoint_set_Z(void *self, const int Z){
  reinterpret_cast<LASpoint *>(self)->set_Z(Z);}
void LASpoint_set_intensity(void *self, const unsigned short intensity){
  reinterpret_cast<LASpoint *>(self)->set_intensity(intensity);}
void LASpoint_set_return_number(void *self, const unsigned char return_number){
  reinterpret_cast<LASpoint *>(self)->set_return_number(return_number);}
void LASpoint_set_number_of_returns(void *self, const unsigned char number_of_returns){
  reinterpret_cast<LASpoint *>(self)->set_number_of_returns(number_of_returns);}
void LASpoint_set_scan_direction_flag(void *self, const unsigned char scan_direction_flag){
  reinterpret_cast<LASpoint *>(self)->set_scan_direction_flag(scan_direction_flag);}
void LASpoint_set_edge_of_flight_line(void *self, const unsigned char edge_of_flight_line){
  reinterpret_cast<LASpoint *>(self)->set_edge_of_flight_line(edge_of_flight_line);}
void LASpoint_set_classification(void *self, unsigned char classification){
  reinterpret_cast<LASpoint *>(self)->set_classification(classification);}
void LASpoint_set_synthetic_flag(void *self, unsigned char synthetic_flag){
  reinterpret_cast<LASpoint *>(self)->set_synthetic_flag(synthetic_flag);}
void LASpoint_set_keypoint_flag(void *self, unsigned char keypoint_flag){
  reinterpret_cast<LASpoint *>(self)->set_keypoint_flag(keypoint_flag);}
void LASpoint_set_withheld_flag(void *self, unsigned char withheld_flag){
  reinterpret_cast<LASpoint *>(self)->set_withheld_flag(withheld_flag);}
void LASpoint_set_scan_angle_rank(void *self, char scan_angle_rank){
  reinterpret_cast<LASpoint *>(self)->set_scan_angle_rank(scan_angle_rank);}
void LASpoint_set_user_data(void *self, unsigned char user_data){
  reinterpret_cast<LASpoint *>(self)->set_user_data(user_data);}
void LASpoint_set_point_source_ID(void *self, unsigned short point_source_ID){
  reinterpret_cast<LASpoint *>(self)->set_point_source_ID(point_source_ID);}
void LASpoint_set_deleted_flag(void *self, unsigned char deleted_flag){
  reinterpret_cast<LASpoint *>(self)->set_deleted_flag(deleted_flag);}
void LASpoint_set_gps_time(void *self, const double gps_time){
  reinterpret_cast<LASpoint *>(self)->set_gps_time(gps_time);}
void LASpoint_set_RGB(void *self, const void * rgb){
  reinterpret_cast<LASpoint *>(self)->set_RGB(
	reinterpret_cast<const unsigned short *>(rgb));}
void LASpoint_set_RGBI(void *self, const void * rgb){
  reinterpret_cast<LASpoint *>(self)->set_RGBI(
	reinterpret_cast<const unsigned short *>(rgb));}
void LASpoint_set_RGBI_1(void *self, const unsigned int band, const unsigned short value){
  reinterpret_cast<LASpoint *>(self)->set_RGBI(band, value);}
void LASpoint_set_R(void *self, const unsigned short R){
  reinterpret_cast<LASpoint *>(self)->set_R(R);}
void LASpoint_set_G(void *self, const unsigned short G){
  reinterpret_cast<LASpoint *>(self)->set_G(G);}
void LASpoint_set_B(void *self, const unsigned short B){
  reinterpret_cast<LASpoint *>(self)->set_B(B);}
void LASpoint_set_I(void *self, const unsigned short I){
  reinterpret_cast<LASpoint *>(self)->set_I(I);}
void LASpoint_set_NIR(void *self, const unsigned short NIR){
  reinterpret_cast<LASpoint *>(self)->set_NIR(NIR);}
double LASpoint_get_x(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_x();}
double LASpoint_get_y(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_y();}
double LASpoint_get_z(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_z();}
bool LASpoint_set_x(void *self, const double x){
  return reinterpret_cast<LASpoint *>(self)->set_x(x);}
bool LASpoint_set_y(void *self, const double y){
  return reinterpret_cast<LASpoint *>(self)->set_y(y);}
bool LASpoint_set_z(void *self, const double z){
  return reinterpret_cast<LASpoint *>(self)->set_z(z);}
bool LASpoint_is_extended_point_type(void *self){
  return reinterpret_cast<const LASpoint *>(self)->is_extended_point_type();}
unsigned char LASpoint_get_extended_classification(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_extended_classification();}
unsigned char LASpoint_get_extended_return_number(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_extended_return_number();}
unsigned char LASpoint_get_extended_number_of_returns(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_extended_number_of_returns();}
short LASpoint_get_extended_scan_angle(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_extended_scan_angle();}
unsigned char LASpoint_get_extended_overlap_flag(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_extended_overlap_flag();}
unsigned char LASpoint_get_extended_scanner_channel(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_extended_scanner_channel();}
void LASpoint_set_extended_classification(void *self, unsigned char extended_classification){
  reinterpret_cast<LASpoint *>(self)->set_extended_classification(extended_classification);}
void LASpoint_set_extended_return_number(void *self, unsigned char extended_return_number){
  reinterpret_cast<LASpoint *>(self)->set_extended_return_number(extended_return_number);}
void LASpoint_set_extended_number_of_returns(void *self, unsigned char extended_number_of_returns){
  reinterpret_cast<LASpoint *>(self)->set_extended_number_of_returns(extended_number_of_returns);}
void LASpoint_set_extended_scan_angle(void *self, short extended_scan_angle){
  reinterpret_cast<LASpoint *>(self)->set_extended_scan_angle(extended_scan_angle);}
void LASpoint_set_extended_overlap_flag(void *self, unsigned char extended_overlap_flag){
  reinterpret_cast<LASpoint *>(self)->set_extended_overlap_flag(extended_overlap_flag);}
void LASpoint_set_extended_scanner_channel(void *self, unsigned char extended_scanner_channel){
  reinterpret_cast<LASpoint *>(self)->set_extended_scanner_channel(extended_scanner_channel);}
float LASpoint_get_scan_angle(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_scan_angle();}
float LASpoint_get_abs_scan_angle(void *self){
  return reinterpret_cast<const LASpoint *>(self)->get_abs_scan_angle();}
void LASpoint_set_scan_angle(void *self, float scan_angle){
  reinterpret_cast<LASpoint *>(self)->set_scan_angle(scan_angle);}
void LASpoint_compute_coordinates(void *self){
  reinterpret_cast<LASpoint *>(self)->compute_coordinates();}
bool LASpoint_compute_XYZ(void *self){
  return reinterpret_cast<LASpoint *>(self)->compute_XYZ();}
bool LASpoint_compute_XYZ_1(void *self, const void * quantizer){
  return reinterpret_cast<LASpoint *>(self)->compute_XYZ(
	reinterpret_cast<const LASquantizer *>(quantizer));}
bool LASpoint_has_attribute(void *self, unsigned int index){
  return reinterpret_cast<const LASpoint *>(self)->has_attribute(index);}
bool LASpoint_get_attribute(void *self, unsigned int index, void * data){
  return reinterpret_cast<const LASpoint *>(self)->get_attribute(index,
	reinterpret_cast<unsigned char *>(data));}
bool LASpoint_set_attribute(void *self, unsigned int index, const void * data){
  return reinterpret_cast<LASpoint *>(self)->set_attribute(index,
	reinterpret_cast<const unsigned char *>(data));}
const void * LASpoint_get_attribute_name(void *self, unsigned int index){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASpoint *>(self)->get_attribute_name(index));}
double LASpoint_get_attribute_as_float(void *self, unsigned int index){
  return reinterpret_cast<const LASpoint *>(self)->get_attribute_as_float(index);}
void LASpoint_set_attribute_as_float(void *self, unsigned int index, double value){
  reinterpret_cast<const LASpoint *>(self)->set_attribute_as_float(index, value);}
void LASpoint_set_attribute_1(void *self, int start, unsigned char data){
  reinterpret_cast<LASpoint *>(self)->set_attribute(start, data);}
void LASpoint_set_attribute_2(void *self, int start, char data){
  reinterpret_cast<LASpoint *>(self)->set_attribute(start, data);}
void LASpoint_set_attribute_3(void *self, int start, unsigned short data){
  reinterpret_cast<LASpoint *>(self)->set_attribute(start, data);}
void LASpoint_set_attribute_4(void *self, int start, short data){
  reinterpret_cast<LASpoint *>(self)->set_attribute(start, data);}
void LASpoint_set_attribute_5(void *self, int start, unsigned int data){
  reinterpret_cast<LASpoint *>(self)->set_attribute(start, data);}
void LASpoint_set_attribute_6(void *self, int start, int data){
  reinterpret_cast<LASpoint *>(self)->set_attribute(start, data);}
void LASpoint_set_attribute_7(void *self, int start, unsigned long long data){
  reinterpret_cast<LASpoint *>(self)->set_attribute(start, data);}
void LASpoint_set_attribute_8(void *self, int start, long long data){
  reinterpret_cast<LASpoint *>(self)->set_attribute(start, data);}
void LASpoint_set_attribute_9(void *self, int start, float data){
  reinterpret_cast<LASpoint *>(self)->set_attribute(start, data);}
void LASpoint_set_attribute_10(void *self, int start, double data){
  reinterpret_cast<LASpoint *>(self)->set_attribute(start, data);}
void LASpoint_destroy(void *self){
  delete reinterpret_cast<LASpoint*>(self);
}


// LASvlr
unsigned short *LASvlr_field_reserved(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASvlr *>(self)->reserved);
}
void *LASvlr_field_user_id(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASvlr *>(self)->user_id);
}
unsigned short *LASvlr_field_record_id(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASvlr *>(self)->record_id);
}
unsigned short *LASvlr_field_record_length_after_header(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASvlr *>(self)->record_length_after_header);
}
void *LASvlr_field_description(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASvlr *>(self)->description);
}
void *LASvlr_field_data(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASvlr *>(self)->data);
}
void *LASvlr_create(){
  return reinterpret_cast<void *>(new LASvlr());
}


// LASevlr
unsigned short *LASevlr_field_reserved(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASevlr *>(self)->reserved);
}
void *LASevlr_field_user_id(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASevlr *>(self)->user_id);
}
unsigned short *LASevlr_field_record_id(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASevlr *>(self)->record_id);
}
long long *LASevlr_field_record_length_after_header(void *self) {
	return reinterpret_cast<long long *>(
		&reinterpret_cast<LASevlr *>(self)->record_length_after_header);
}
void *LASevlr_field_description(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASevlr *>(self)->description);
}
void *LASevlr_field_data(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASevlr *>(self)->data);
}
void *LASevlr_create(){
  return reinterpret_cast<void *>(new LASevlr());
}


// LASvlr_geo_keys
unsigned short *LASvlr_geo_keys_field_key_directory_version(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASvlr_geo_keys *>(self)->key_directory_version);
}
unsigned short *LASvlr_geo_keys_field_key_revision(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASvlr_geo_keys *>(self)->key_revision);
}
unsigned short *LASvlr_geo_keys_field_minor_revision(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASvlr_geo_keys *>(self)->minor_revision);
}
unsigned short *LASvlr_geo_keys_field_number_of_keys(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASvlr_geo_keys *>(self)->number_of_keys);
}


// LASvlr_key_entry
unsigned short *LASvlr_key_entry_field_key_id(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASvlr_key_entry *>(self)->key_id);
}
unsigned short *LASvlr_key_entry_field_tiff_tag_location(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASvlr_key_entry *>(self)->tiff_tag_location);
}
unsigned short *LASvlr_key_entry_field_count(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASvlr_key_entry *>(self)->count);
}
unsigned short *LASvlr_key_entry_field_value_offset(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASvlr_key_entry *>(self)->value_offset);
}


// LASvlr_classification
unsigned char *LASvlr_classification_field_class_number(void *self) {
	return reinterpret_cast<unsigned char *>(
		&reinterpret_cast<LASvlr_classification *>(self)->class_number);
}
void *LASvlr_classification_field_description(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASvlr_classification *>(self)->description);
}


// LASvlr_wave_packet_descr
void *LASvlr_wave_packet_descr_create(){
  return reinterpret_cast<void *>(new LASvlr_wave_packet_descr());
}
void LASvlr_wave_packet_descr_clean(void *self){
  reinterpret_cast<LASvlr_wave_packet_descr *>(self)->clean();}
unsigned char LASvlr_wave_packet_descr_getBitsPerSample(void *self){
  return reinterpret_cast<const LASvlr_wave_packet_descr *>(self)->getBitsPerSample();}
unsigned char LASvlr_wave_packet_descr_getCompressionType(void *self){
  return reinterpret_cast<const LASvlr_wave_packet_descr *>(self)->getCompressionType();}
unsigned int LASvlr_wave_packet_descr_getNumberOfSamples(void *self){
  return reinterpret_cast<const LASvlr_wave_packet_descr *>(self)->getNumberOfSamples();}
unsigned int LASvlr_wave_packet_descr_getTemporalSpacing(void *self){
  return reinterpret_cast<const LASvlr_wave_packet_descr *>(self)->getTemporalSpacing();}
double LASvlr_wave_packet_descr_getDigitizerGain(void *self){
  return reinterpret_cast<const LASvlr_wave_packet_descr *>(self)->getDigitizerGain();}
double LASvlr_wave_packet_descr_getDigitizerOffset(void *self){
  return reinterpret_cast<const LASvlr_wave_packet_descr *>(self)->getDigitizerOffset();}
void LASvlr_wave_packet_descr_setBitsPerSample(void *self, unsigned char bps){
  reinterpret_cast<LASvlr_wave_packet_descr *>(self)->setBitsPerSample(bps);}
void LASvlr_wave_packet_descr_setCompressionType(void *self, unsigned char compression){
  reinterpret_cast<LASvlr_wave_packet_descr *>(self)->setCompressionType(compression);}
void LASvlr_wave_packet_descr_setNumberOfSamples(void *self, unsigned int samples){
  reinterpret_cast<LASvlr_wave_packet_descr *>(self)->setNumberOfSamples(samples);}
void LASvlr_wave_packet_descr_setTemporalSpacing(void *self, unsigned int spacing){
  reinterpret_cast<LASvlr_wave_packet_descr *>(self)->setTemporalSpacing(spacing);}
void LASvlr_wave_packet_descr_setDigitizerGain(void *self, double gain){
  reinterpret_cast<LASvlr_wave_packet_descr *>(self)->setDigitizerGain(gain);}
void LASvlr_wave_packet_descr_setDigitizerOffset(void *self, double offset){
  reinterpret_cast<LASvlr_wave_packet_descr *>(self)->setDigitizerOffset(offset);}


// LASheader
void *LASheader_field_file_signature(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->file_signature);
}
unsigned short *LASheader_field_file_source_ID(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASheader *>(self)->file_source_ID);
}
unsigned short *LASheader_field_global_encoding(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASheader *>(self)->global_encoding);
}
unsigned int *LASheader_field_project_ID_GUID_data_1(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASheader *>(self)->project_ID_GUID_data_1);
}
unsigned short *LASheader_field_project_ID_GUID_data_2(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASheader *>(self)->project_ID_GUID_data_2);
}
unsigned short *LASheader_field_project_ID_GUID_data_3(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASheader *>(self)->project_ID_GUID_data_3);
}
void *LASheader_field_project_ID_GUID_data_4(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->project_ID_GUID_data_4);
}
unsigned char *LASheader_field_version_major(void *self) {
	return reinterpret_cast<unsigned char *>(
		&reinterpret_cast<LASheader *>(self)->version_major);
}
unsigned char *LASheader_field_version_minor(void *self) {
	return reinterpret_cast<unsigned char *>(
		&reinterpret_cast<LASheader *>(self)->version_minor);
}
void *LASheader_field_system_identifier(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->system_identifier);
}
void *LASheader_field_generating_software(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->generating_software);
}
unsigned short *LASheader_field_file_creation_day(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASheader *>(self)->file_creation_day);
}
unsigned short *LASheader_field_file_creation_year(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASheader *>(self)->file_creation_year);
}
unsigned short *LASheader_field_header_size(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASheader *>(self)->header_size);
}
unsigned int *LASheader_field_offset_to_point_data(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASheader *>(self)->offset_to_point_data);
}
unsigned int *LASheader_field_number_of_variable_length_records(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASheader *>(self)->number_of_variable_length_records);
}
unsigned char *LASheader_field_point_data_format(void *self) {
	return reinterpret_cast<unsigned char *>(
		&reinterpret_cast<LASheader *>(self)->point_data_format);
}
unsigned short *LASheader_field_point_data_record_length(void *self) {
	return reinterpret_cast<unsigned short *>(
		&reinterpret_cast<LASheader *>(self)->point_data_record_length);
}
unsigned int *LASheader_field_number_of_point_records(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASheader *>(self)->number_of_point_records);
}
void *LASheader_field_number_of_points_by_return(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->number_of_points_by_return);
}
double *LASheader_field_max_x(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASheader *>(self)->max_x);
}
double *LASheader_field_min_x(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASheader *>(self)->min_x);
}
double *LASheader_field_max_y(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASheader *>(self)->max_y);
}
double *LASheader_field_min_y(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASheader *>(self)->min_y);
}
double *LASheader_field_max_z(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASheader *>(self)->max_z);
}
double *LASheader_field_min_z(void *self) {
	return reinterpret_cast<double *>(
		&reinterpret_cast<LASheader *>(self)->min_z);
}
unsigned long long *LASheader_field_start_of_waveform_data_packet_record(void *self) {
	return reinterpret_cast<unsigned long long *>(
		&reinterpret_cast<LASheader *>(self)->start_of_waveform_data_packet_record);
}
unsigned long long *LASheader_field_start_of_first_extended_variable_length_record(void *self) {
	return reinterpret_cast<unsigned long long *>(
		&reinterpret_cast<LASheader *>(self)->start_of_first_extended_variable_length_record);
}
unsigned int *LASheader_field_number_of_extended_variable_length_records(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASheader *>(self)->number_of_extended_variable_length_records);
}
unsigned long long *LASheader_field_extended_number_of_point_records(void *self) {
	return reinterpret_cast<unsigned long long *>(
		&reinterpret_cast<LASheader *>(self)->extended_number_of_point_records);
}
void *LASheader_field_extended_number_of_points_by_return(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->extended_number_of_points_by_return);
}
unsigned int *LASheader_field_user_data_in_header_size(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASheader *>(self)->user_data_in_header_size);
}
void *LASheader_field_user_data_in_header(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->user_data_in_header);
}
void *LASheader_field_vlrs(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->vlrs);
}
void *LASheader_field_evlrs(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->evlrs);
}
void *LASheader_field_vlr_geo_keys(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->vlr_geo_keys);
}
void *LASheader_field_vlr_geo_key_entries(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->vlr_geo_key_entries);
}
void *LASheader_field_vlr_geo_double_params(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->vlr_geo_double_params);
}
void *LASheader_field_vlr_geo_ascii_params(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->vlr_geo_ascii_params);
}
void *LASheader_field_vlr_geo_ogc_wkt_math(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->vlr_geo_ogc_wkt_math);
}
void *LASheader_field_vlr_geo_ogc_wkt(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->vlr_geo_ogc_wkt);
}
void *LASheader_field_vlr_classification(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->vlr_classification);
}
void *LASheader_field_vlr_wave_packet_descr(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->vlr_wave_packet_descr);
}
void *LASheader_field_laszip(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->laszip);
}
void *LASheader_field_vlr_lastiling(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->vlr_lastiling);
}
void *LASheader_field_vlr_lasoriginal(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->vlr_lasoriginal);
}
unsigned int *LASheader_field_user_data_after_header_size(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASheader *>(self)->user_data_after_header_size);
}
void *LASheader_field_user_data_after_header(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASheader *>(self)->user_data_after_header);
}
void *LASheader_create(){
  return reinterpret_cast<void *>(new LASheader());
}
void LASheader_set_bounding_box(void *self, double min_x, double min_y, double min_z, double max_x, double max_y, double max_z, bool auto_scale, bool auto_offset){
  reinterpret_cast<LASheader *>(self)->set_bounding_box(min_x, min_y, min_z, max_x, max_y, max_z, auto_scale, auto_offset);}
void LASheader_set_global_encoding_bit(void *self, int bit){
  reinterpret_cast<LASheader *>(self)->set_global_encoding_bit(bit);}
void LASheader_unset_global_encoding_bit(void *self, int bit){
  reinterpret_cast<LASheader *>(self)->unset_global_encoding_bit(bit);}
bool LASheader_get_global_encoding_bit(void *self, int bit){
  return reinterpret_cast<const LASheader *>(self)->get_global_encoding_bit(bit);}
void LASheader_clean_las_header(void *self){
  reinterpret_cast<LASheader *>(self)->clean_las_header();}
void LASheader_clean_user_data_in_header(void *self){
  reinterpret_cast<LASheader *>(self)->clean_user_data_in_header();}
void LASheader_clean_vlrs(void *self){
  reinterpret_cast<LASheader *>(self)->clean_vlrs();}
void LASheader_clean_evlrs(void *self){
  reinterpret_cast<LASheader *>(self)->clean_evlrs();}
void LASheader_clean_laszip(void *self){
  reinterpret_cast<LASheader *>(self)->clean_laszip();}
void LASheader_clean_lastiling(void *self){
  reinterpret_cast<LASheader *>(self)->clean_lastiling();}
void LASheader_clean_lasoriginal(void *self){
  reinterpret_cast<LASheader *>(self)->clean_lasoriginal();}
void LASheader_clean_user_data_after_header(void *self){
  reinterpret_cast<LASheader *>(self)->clean_user_data_after_header();}
void LASheader_clean(void *self){
  reinterpret_cast<LASheader *>(self)->clean();}
void LASheader_unlink(void *self){
  reinterpret_cast<LASheader *>(self)->unlink();}
bool LASheader_check(void *self){
  return reinterpret_cast<const LASheader *>(self)->check();}
bool LASheader_is_compressed(void *self){
  return reinterpret_cast<const LASheader *>(self)->is_compressed();}
bool LASheader_is_lonlat(void *self, const float extend){
  return reinterpret_cast<const LASheader *>(self)->is_lonlat(extend);}
bool LASheader_add_vlr(void *self, const void * user_id, const unsigned short record_id, const unsigned short record_length_after_header, void * data, const bool keep_description, const void * description, const bool keep_existing){
  return reinterpret_cast<LASheader *>(self)->add_vlr(
	reinterpret_cast<const char *>(user_id), record_id, record_length_after_header,
	reinterpret_cast<unsigned char *>(data), keep_description,
	reinterpret_cast<const char *>(description), keep_existing);}
const void * LASheader_get_vlr(void *self, const void * user_id, unsigned short record_id){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASheader *>(self)->get_vlr(
	reinterpret_cast<const char *>(user_id), record_id));}
bool LASheader_remove_vlr(void *self, unsigned int i, bool delete_data){
  return reinterpret_cast<LASheader *>(self)->remove_vlr(i, delete_data);}
bool LASheader_remove_vlr_1(void *self, const void * user_id, unsigned short record_id){
  return reinterpret_cast<LASheader *>(self)->remove_vlr(
	reinterpret_cast<const char *>(user_id), record_id);}
void LASheader_add_evlr(void *self, const void * user_id, const unsigned short record_id, const long long record_length_after_header, void * data, const bool keep_description, const void * description, const bool keep_existing){
  reinterpret_cast<LASheader *>(self)->add_evlr(
	reinterpret_cast<const char *>(user_id), record_id, record_length_after_header,
	reinterpret_cast<unsigned char *>(data), keep_description,
	reinterpret_cast<const char *>(description), keep_existing);}
bool LASheader_remove_evlr(void *self, unsigned int i, bool delete_data){
  return reinterpret_cast<LASheader *>(self)->remove_evlr(i, delete_data);}
bool LASheader_remove_evlr_1(void *self, const void * user_id, unsigned short record_id){
  return reinterpret_cast<LASheader *>(self)->remove_evlr(
	reinterpret_cast<const char *>(user_id), record_id);}
void LASheader_set_lastiling(void *self, unsigned int level, unsigned int level_index, unsigned int implicit_levels, bool buffer, bool reversible, float min_x, float max_x, float min_y, float max_y){
  reinterpret_cast<LASheader *>(self)->set_lastiling(level, level_index, implicit_levels, buffer, reversible, min_x, max_x, min_y, max_y);}
void LASheader_set_lasoriginal(void *self){
  reinterpret_cast<LASheader *>(self)->set_lasoriginal();}
bool LASheader_restore_lasoriginal(void *self){
  return reinterpret_cast<LASheader *>(self)->restore_lasoriginal();}
bool LASheader_set_geo_keys(void *self, const int number_of_keys, const void * geo_keys){
  return reinterpret_cast<LASheader *>(self)->set_geo_keys(number_of_keys,
	reinterpret_cast<const LASvlr_key_entry *>(geo_keys));}
bool LASheader_set_geo_double_params(void *self, const int num_geo_double_params, const void * geo_double_params){
  return reinterpret_cast<LASheader *>(self)->set_geo_double_params(num_geo_double_params,
	reinterpret_cast<const double *>(geo_double_params));}
void LASheader_del_geo_double_params(void *self){
  reinterpret_cast<LASheader *>(self)->del_geo_double_params();}
bool LASheader_set_geo_ascii_params(void *self, const int num_geo_ascii_params, const void * geo_ascii_params){
  return reinterpret_cast<LASheader *>(self)->set_geo_ascii_params(num_geo_ascii_params,
	reinterpret_cast<const char *>(geo_ascii_params));}
void LASheader_del_geo_ascii_params(void *self){
  reinterpret_cast<LASheader *>(self)->del_geo_ascii_params();}
void LASheader_set_geo_wkt_ogc_math(void *self, const int num_geo_wkt_ogc_math, const void * geo_wkt_ogc_math){
  reinterpret_cast<LASheader *>(self)->set_geo_wkt_ogc_math(num_geo_wkt_ogc_math,
	reinterpret_cast<const char *>(geo_wkt_ogc_math));}
void LASheader_del_geo_wkt_ogc_math(void *self){
  reinterpret_cast<LASheader *>(self)->del_geo_wkt_ogc_math();}
void LASheader_set_geo_ogc_wkt(void *self, const int num_geo_ogc_wkt, const void * geo_ogc_wkt, bool in_evlr){
  reinterpret_cast<LASheader *>(self)->set_geo_ogc_wkt(num_geo_ogc_wkt,
	reinterpret_cast<const char *>(geo_ogc_wkt), in_evlr);}
void LASheader_del_geo_ogc_wkt(void *self){
  reinterpret_cast<LASheader *>(self)->del_geo_ogc_wkt();}
bool LASheader_update_extra_bytes_vlr(void *self, const bool keep_description){
  return reinterpret_cast<LASheader *>(self)->update_extra_bytes_vlr(keep_description);}
void LASheader_destroy(void *self){
  delete reinterpret_cast<LASheader*>(self);
}


// LASignore
void LASignore_usage(void *self){
  reinterpret_cast<const LASignore *>(self)->usage();}
void LASignore_ignore_class(void *self, unsigned char classification){
  reinterpret_cast<LASignore *>(self)->ignore_class(classification);}
void LASignore_dont_ignore_class(void *self, unsigned char classification){
  reinterpret_cast<LASignore *>(self)->dont_ignore_class(classification);}
int LASignore_unparse(void *self, void * string){
  return reinterpret_cast<const LASignore *>(self)->unparse(
	reinterpret_cast<char *>(string));}
bool LASignore_parse_1(void *self, unsigned int curr_parameter, const unsigned int num_parameters, const void * parameters){
  return reinterpret_cast<LASignore *>(self)->parse(curr_parameter, num_parameters,
	reinterpret_cast<const double *>(parameters));}
unsigned int LASignore_get_decompress_selective(void *self){
  return reinterpret_cast<const LASignore *>(self)->get_decompress_selective();}
bool LASignore_ignore(void *self, const void * point){
  return reinterpret_cast<const LASignore *>(self)->ignore(
	reinterpret_cast<const LASpoint *>(point));}
void *LASignore_create(){
  return reinterpret_cast<void *>(new LASignore());
}
void LASignore_destroy(void *self){
  delete reinterpret_cast<LASignore*>(self);
}


// LASreader
void *LASreader_field_header(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASreader *>(self)->header);
}
void *LASreader_field_point(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASreader *>(self)->point);
}
long long *LASreader_field_npoints(void *self) {
	return reinterpret_cast<long long *>(
		&reinterpret_cast<LASreader *>(self)->npoints);
}
long long *LASreader_field_p_count(void *self) {
	return reinterpret_cast<long long *>(
		&reinterpret_cast<LASreader *>(self)->p_count);
}
bool LASreader_has_layers(void *self){
  return reinterpret_cast<const LASreader *>(self)->has_layers();}
void LASreader_set_index(void *self, void * index){
  reinterpret_cast<LASreader *>(self)->set_index(
	reinterpret_cast<LASindex *>(index));}
void * LASreader_get_index(void *self){
  return reinterpret_cast<void * >(reinterpret_cast<const LASreader *>(self)->get_index());}
void LASreader_set_filter(void *self, void * filter){
  reinterpret_cast<LASreader *>(self)->set_filter(
	reinterpret_cast<LASfilter *>(filter));}
void * LASreader_get_filter(void *self){
  return reinterpret_cast<void * >(reinterpret_cast<const LASreader *>(self)->get_filter());}
void LASreader_set_transform(void *self, void * transform){
  reinterpret_cast<LASreader *>(self)->set_transform(
	reinterpret_cast<LAStransform *>(transform));}
void * LASreader_get_transform(void *self){
  return reinterpret_cast<void * >(reinterpret_cast<const LASreader *>(self)->get_transform());}
void LASreader_set_ignore(void *self, void * ignore){
  reinterpret_cast<LASreader *>(self)->set_ignore(
	reinterpret_cast<LASignore *>(ignore));}
void * LASreader_get_ignore(void *self){
  return reinterpret_cast<void * >(reinterpret_cast<const LASreader *>(self)->get_ignore());}
unsigned int LASreader_get_inside(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_inside();}
bool LASreader_inside_none(void *self){
  return reinterpret_cast<LASreader *>(self)->inside_none();}
bool LASreader_inside_tile(void *self, const float ll_x, const float ll_y, const float size){
  return reinterpret_cast<LASreader *>(self)->inside_tile(ll_x, ll_y, size);}
float LASreader_get_t_ll_x(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_t_ll_x();}
float LASreader_get_t_ll_y(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_t_ll_y();}
float LASreader_get_t_size(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_t_size();}
bool LASreader_inside_circle(void *self, const double center_x, const double center_y, const double radius){
  return reinterpret_cast<LASreader *>(self)->inside_circle(center_x, center_y, radius);}
double LASreader_get_c_center_x(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_c_center_x();}
double LASreader_get_c_center_y(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_c_center_y();}
double LASreader_get_c_radius(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_c_radius();}
bool LASreader_inside_rectangle(void *self, const double min_x, const double min_y, const double max_x, const double max_y){
  return reinterpret_cast<LASreader *>(self)->inside_rectangle(min_x, min_y, max_x, max_y);}
double LASreader_get_r_min_x(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_r_min_x();}
double LASreader_get_r_min_y(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_r_min_y();}
double LASreader_get_r_max_x(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_r_max_x();}
double LASreader_get_r_max_y(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_r_max_y();}
bool LASreader_read_point(void *self){
  return reinterpret_cast<LASreader *>(self)->read_point();}
bool LASreader_ignore_point(void *self){
  return reinterpret_cast<LASreader *>(self)->ignore_point();}
void LASreader_compute_coordinates(void *self){
  reinterpret_cast<LASreader *>(self)->compute_coordinates();}
double LASreader_get_min_x(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_min_x();}
double LASreader_get_min_y(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_min_y();}
double LASreader_get_min_z(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_min_z();}
double LASreader_get_max_x(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_max_x();}
double LASreader_get_max_y(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_max_y();}
double LASreader_get_max_z(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_max_z();}
double LASreader_get_x(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_x();}
double LASreader_get_y(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_y();}
double LASreader_get_z(void *self){
  return reinterpret_cast<const LASreader *>(self)->get_z();}
double LASreader_get_x_1(void *self, const int x){
  return reinterpret_cast<const LASreader *>(self)->get_x(x);}
double LASreader_get_y_1(void *self, const int y){
  return reinterpret_cast<const LASreader *>(self)->get_y(y);}
double LASreader_get_z_1(void *self, const int z){
  return reinterpret_cast<const LASreader *>(self)->get_z(z);}
long long LASreader_get_X(void *self, const double x){
  return reinterpret_cast<const LASreader *>(self)->get_X(x);}
long long LASreader_get_Y(void *self, const double y){
  return reinterpret_cast<const LASreader *>(self)->get_Y(y);}
long long LASreader_get_Z(void *self, const double z){
  return reinterpret_cast<const LASreader *>(self)->get_Z(z);}
void LASreader_destroy(void *self){
  delete reinterpret_cast<LASreader*>(self);
}
void LASreader_dealloc(void *self){
  reinterpret_cast<LASreader *>(self)->dealloc();}


// LASwaveform13reader
unsigned int *LASwaveform13reader_field_nbits(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->nbits);
}
unsigned int *LASwaveform13reader_field_nsamples(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->nsamples);
}
unsigned int *LASwaveform13reader_field_temporal(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->temporal);
}
float *LASwaveform13reader_field_location(void *self) {
	return reinterpret_cast<float *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->location);
}
void *LASwaveform13reader_field_XYZt(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->XYZt);
}
void *LASwaveform13reader_field_XYZreturn(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->XYZreturn);
}
void *LASwaveform13reader_field_XYZsample(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->XYZsample);
}
unsigned int *LASwaveform13reader_field_s_count(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->s_count);
}
unsigned int *LASwaveform13reader_field_sample(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->sample);
}
unsigned int *LASwaveform13reader_field_sampleMin(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->sampleMin);
}
unsigned int *LASwaveform13reader_field_sampleMax(void *self) {
	return reinterpret_cast<unsigned int *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->sampleMax);
}
void *LASwaveform13reader_field_samples(void *self) {
	return reinterpret_cast<void *>(
		&reinterpret_cast<LASwaveform13reader *>(self)->samples);
}
bool LASwaveform13reader_open(void *self, const void * file_name, long long start_of_waveform_data_packet_record, const void * wave_packet_descr){
  return reinterpret_cast<LASwaveform13reader *>(self)->open(
	reinterpret_cast<const char *>(file_name), start_of_waveform_data_packet_record,
	reinterpret_cast<const LASvlr_wave_packet_descr *const *>(wave_packet_descr));}
bool LASwaveform13reader_is_compressed(void *self){
  return reinterpret_cast<const LASwaveform13reader *>(self)->is_compressed();}
bool LASwaveform13reader_read_waveform(void *self, const void * point){
  return reinterpret_cast<LASwaveform13reader *>(self)->read_waveform(
	reinterpret_cast<const LASpoint *>(point));}
bool LASwaveform13reader_get_samples(void *self){
  return reinterpret_cast<LASwaveform13reader *>(self)->get_samples();}
bool LASwaveform13reader_has_samples(void *self){
  return reinterpret_cast<LASwaveform13reader *>(self)->has_samples();}
bool LASwaveform13reader_get_samples_xyz(void *self){
  return reinterpret_cast<LASwaveform13reader *>(self)->get_samples_xyz();}
bool LASwaveform13reader_has_samples_xyz(void *self){
  return reinterpret_cast<LASwaveform13reader *>(self)->has_samples_xyz();}
void LASwaveform13reader_close(void *self){
  reinterpret_cast<LASwaveform13reader *>(self)->close();}
void *LASwaveform13reader_create(){
  return reinterpret_cast<void *>(new LASwaveform13reader());
}
void LASwaveform13reader_destroy(void *self){
  delete reinterpret_cast<LASwaveform13reader*>(self);
}


// LASreadOpener
void LASreadOpener_set_io_ibuffer_size(void *self, const unsigned int buffer_size){
  reinterpret_cast<LASreadOpener *>(self)->set_io_ibuffer_size(buffer_size);}
unsigned int LASreadOpener_get_io_ibuffer_size(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->get_io_ibuffer_size();}
unsigned int LASreadOpener_get_file_name_number(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->get_file_name_number();}
unsigned int LASreadOpener_get_file_name_current(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->get_file_name_current();}
const void * LASreadOpener_get_file_name(void *self){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_file_name());}
const void * LASreadOpener_get_file_name_only(void *self){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_file_name_only());}
const void * LASreadOpener_get_file_extension_only(void *self){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_file_extension_only());}
const void * LASreadOpener_get_file_name_1(void *self, unsigned int number){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_file_name(number));}
const void * LASreadOpener_get_file_name_only_1(void *self, unsigned int number){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_file_name_only(number));}
const void * LASreadOpener_get_file_extension_only_1(void *self, unsigned int number){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_file_extension_only(number));}
void * LASreadOpener_get_file_name_base(void *self){
  return reinterpret_cast<void * >(reinterpret_cast<const LASreadOpener *>(self)->get_file_name_base());}
void * LASreadOpener_get_file_name_base_1(void *self, unsigned int number){
  return reinterpret_cast<void * >(reinterpret_cast<const LASreadOpener *>(self)->get_file_name_base(number));}
void LASreadOpener_set_file_name(void *self, const void * file_name, bool unique){
  reinterpret_cast<LASreadOpener *>(self)->set_file_name(
	reinterpret_cast<const char *>(file_name), unique);}
bool LASreadOpener_add_file_name(void *self, const void * file_name, bool unique){
  return reinterpret_cast<LASreadOpener *>(self)->add_file_name(
	reinterpret_cast<const char *>(file_name), unique);}
bool LASreadOpener_add_list_of_files(void *self, const void * list_of_files, bool unique){
  return reinterpret_cast<LASreadOpener *>(self)->add_list_of_files(
	reinterpret_cast<const char *>(list_of_files), unique);}
void LASreadOpener_delete_file_name(void *self, unsigned int file_name_id){
  reinterpret_cast<LASreadOpener *>(self)->delete_file_name(file_name_id);}
bool LASreadOpener_set_file_name_current(void *self, unsigned int file_name_id){
  return reinterpret_cast<LASreadOpener *>(self)->set_file_name_current(file_name_id);}
int LASreadOpener_get_file_format(void *self, unsigned int number){
  return reinterpret_cast<const LASreadOpener *>(self)->get_file_format(number);}
void LASreadOpener_set_merged(void *self, const bool merged){
  reinterpret_cast<LASreadOpener *>(self)->set_merged(merged);}
bool LASreadOpener_is_merged(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->is_merged();}
void LASreadOpener_set_stored(void *self, const bool stored){
  reinterpret_cast<LASreadOpener *>(self)->set_stored(stored);}
bool LASreadOpener_is_stored(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->is_stored();}
void LASreadOpener_set_buffer_size(void *self, const float buffer_size){
  reinterpret_cast<LASreadOpener *>(self)->set_buffer_size(buffer_size);}
float LASreadOpener_get_buffer_size(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->get_buffer_size();}
void LASreadOpener_set_neighbor_file_name(void *self, const void * neighbor_file_name, bool unique){
  reinterpret_cast<LASreadOpener *>(self)->set_neighbor_file_name(
	reinterpret_cast<const char *>(neighbor_file_name), unique);}
bool LASreadOpener_add_neighbor_file_name(void *self, const void * neighbor_file_name, bool unique){
  return reinterpret_cast<LASreadOpener *>(self)->add_neighbor_file_name(
	reinterpret_cast<const char *>(neighbor_file_name), unique);}
bool LASreadOpener_add_neighbor_file_name_1(void *self, const void * file_name, long long npoints, double min_x, double min_y, double max_x, double max_y, bool unique){
  return reinterpret_cast<LASreadOpener *>(self)->add_neighbor_file_name(
	reinterpret_cast<const char *>(file_name), npoints, min_x, min_y, max_x, max_y, unique);}
bool LASreadOpener_add_neighbor_list_of_files(void *self, const void * list_of_files, bool unique){
  return reinterpret_cast<LASreadOpener *>(self)->add_neighbor_list_of_files(
	reinterpret_cast<const char *>(list_of_files), unique);}
void LASreadOpener_set_auto_reoffset(void *self, const bool auto_reoffset){
  reinterpret_cast<LASreadOpener *>(self)->set_auto_reoffset(auto_reoffset);}
bool LASreadOpener_is_auto_reoffset(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->is_auto_reoffset();}
void LASreadOpener_set_files_are_flightlines(void *self, const int files_are_flightlines){
  reinterpret_cast<LASreadOpener *>(self)->set_files_are_flightlines(files_are_flightlines);}
int LASreadOpener_are_files_flightlines(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->are_files_flightlines();}
void LASreadOpener_set_files_are_flightlines_index(void *self, const int files_are_flightlines_index){
  reinterpret_cast<LASreadOpener *>(self)->set_files_are_flightlines_index(files_are_flightlines_index);}
int LASreadOpener_get_files_flight_index(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->get_files_flight_index();}
void LASreadOpener_set_apply_file_source_ID(void *self, const bool apply_file_source_ID){
  reinterpret_cast<LASreadOpener *>(self)->set_apply_file_source_ID(apply_file_source_ID);}
bool LASreadOpener_applying_file_source_ID(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->applying_file_source_ID();}
void LASreadOpener_set_scale_factor(void *self, const void * scale_factor){
  reinterpret_cast<LASreadOpener *>(self)->set_scale_factor(
	reinterpret_cast<const double *>(scale_factor));}
const void * LASreadOpener_get_scale_factor(void *self){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_scale_factor());}
void LASreadOpener_set_offset(void *self, const void * offset){
  reinterpret_cast<LASreadOpener *>(self)->set_offset(
	reinterpret_cast<const double *>(offset));}
const void * LASreadOpener_get_offset(void *self){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_offset());}
void LASreadOpener_set_translate_intensity(void *self, const float translation){
  reinterpret_cast<LASreadOpener *>(self)->set_translate_intensity(translation);}
void LASreadOpener_set_scale_intensity(void *self, const float scale){
  reinterpret_cast<LASreadOpener *>(self)->set_scale_intensity(scale);}
void LASreadOpener_set_translate_scan_angle(void *self, const float translate_scan_angle){
  reinterpret_cast<LASreadOpener *>(self)->set_translate_scan_angle(translate_scan_angle);}
void LASreadOpener_set_scale_scan_angle(void *self, const float scale_scan_angle){
  reinterpret_cast<LASreadOpener *>(self)->set_scale_scan_angle(scale_scan_angle);}
void LASreadOpener_add_attribute(void *self, int data_type, const void * name, const void * description, double scale, double offset, double pre_scale, double pre_offset, double no_data){
  reinterpret_cast<LASreadOpener *>(self)->add_attribute(data_type,
	reinterpret_cast<const char *>(name),
	reinterpret_cast<const char *>(description), scale, offset, pre_scale, pre_offset, no_data);}
bool LASreadOpener_set_point_type(void *self, unsigned char point_type){
  return reinterpret_cast<LASreadOpener *>(self)->set_point_type(point_type);}
void LASreadOpener_set_parse_string(void *self, const void * parse_string){
  reinterpret_cast<LASreadOpener *>(self)->set_parse_string(
	reinterpret_cast<const char *>(parse_string));}
void LASreadOpener_set_skip_lines(void *self, const unsigned int number_of_lines){
  reinterpret_cast<LASreadOpener *>(self)->set_skip_lines(number_of_lines);}
void LASreadOpener_set_populate_header(void *self, bool populate_header){
  reinterpret_cast<LASreadOpener *>(self)->set_populate_header(populate_header);}
void LASreadOpener_set_keep_lastiling(void *self, bool keep_lastiling){
  reinterpret_cast<LASreadOpener *>(self)->set_keep_lastiling(keep_lastiling);}
void LASreadOpener_set_pipe_on(void *self, bool pipe_on){
  reinterpret_cast<LASreadOpener *>(self)->set_pipe_on(pipe_on);}
const void * LASreadOpener_get_parse_string(void *self){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_parse_string());}
void LASreadOpener_usage(void *self){
  reinterpret_cast<const LASreadOpener *>(self)->usage();}
void LASreadOpener_set_decompress_selective(void *self, unsigned int decompress_selective){
  reinterpret_cast<LASreadOpener *>(self)->set_decompress_selective(decompress_selective);}
void LASreadOpener_set_inside_tile(void *self, const float ll_x, const float ll_y, const float size){
  reinterpret_cast<LASreadOpener *>(self)->set_inside_tile(ll_x, ll_y, size);}
void LASreadOpener_set_inside_circle(void *self, const double center_x, const double center_y, const double radius){
  reinterpret_cast<LASreadOpener *>(self)->set_inside_circle(center_x, center_y, radius);}
void LASreadOpener_set_inside_rectangle(void *self, const double min_x, const double min_y, const double max_x, const double max_y){
  reinterpret_cast<LASreadOpener *>(self)->set_inside_rectangle(min_x, min_y, max_x, max_y);}
bool LASreadOpener_parse(void *self, int argc, void * argv, bool parse_ignore){
  return reinterpret_cast<LASreadOpener *>(self)->parse(argc,
	reinterpret_cast<char **>(argv), parse_ignore);}
bool LASreadOpener_is_piped(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->is_piped();}
bool LASreadOpener_is_buffered(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->is_buffered();}
bool LASreadOpener_is_header_populated(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->is_header_populated();}
bool LASreadOpener_active(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->active();}
bool LASreadOpener_is_inside(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->is_inside();}
int LASreadOpener_unparse(void *self, void * string){
  return reinterpret_cast<const LASreadOpener *>(self)->unparse(
	reinterpret_cast<char *>(string));}
void LASreadOpener_set_filter(void *self, void * filter){
  reinterpret_cast<LASreadOpener *>(self)->set_filter(
	reinterpret_cast<LASfilter *>(filter));}
void * LASreadOpener_get_filter(void *self){
  return reinterpret_cast<void * >(reinterpret_cast<LASreadOpener *>(self)->get_filter());}
void LASreadOpener_set_transform(void *self, void * transform){
  reinterpret_cast<LASreadOpener *>(self)->set_transform(
	reinterpret_cast<LAStransform *>(transform));}
void * LASreadOpener_get_transform(void *self){
  return reinterpret_cast<void * >(reinterpret_cast<LASreadOpener *>(self)->get_transform());}
void LASreadOpener_set_ignore(void *self, void * ignore){
  reinterpret_cast<LASreadOpener *>(self)->set_ignore(
	reinterpret_cast<LASignore *>(ignore));}
void * LASreadOpener_get_ignore(void *self){
  return reinterpret_cast<void * >(reinterpret_cast<LASreadOpener *>(self)->get_ignore());}
void LASreadOpener_reset(void *self){
  reinterpret_cast<LASreadOpener *>(self)->reset();}
const void * LASreadOpener_get_temp_file_base(void *self){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_temp_file_base());}
void * LASreadOpener_open(void *self, const void * other_file_name, bool reset_after_other){
  return reinterpret_cast<void * >(reinterpret_cast<LASreadOpener *>(self)->open(
	reinterpret_cast<const char *>(other_file_name), reset_after_other));}
bool LASreadOpener_reopen(void *self, void * lasreader, bool remain_buffered){
  return reinterpret_cast<LASreadOpener *>(self)->reopen(
	reinterpret_cast<LASreader *>(lasreader), remain_buffered);}
void * LASreadOpener_open_waveform13(void *self, const void * lasheader){
  return reinterpret_cast<void * >(reinterpret_cast<LASreadOpener *>(self)->open_waveform13(
	reinterpret_cast<const LASheader *>(lasheader)));}
int LASreadOpener_get_number_attributes(void *self){
  return reinterpret_cast<const LASreadOpener *>(self)->get_number_attributes();}
int LASreadOpener_get_attribute_data_type(void *self, unsigned int index){
  return reinterpret_cast<const LASreadOpener *>(self)->get_attribute_data_type(index);}
const void * LASreadOpener_get_attribute_name(void *self, unsigned int index){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_attribute_name(index));}
const void * LASreadOpener_get_attribute_description(void *self, unsigned int index){
  return reinterpret_cast<const void * >(reinterpret_cast<const LASreadOpener *>(self)->get_attribute_description(index));}
double LASreadOpener_get_attribute_scale(void *self, unsigned int index){
  return reinterpret_cast<const LASreadOpener *>(self)->get_attribute_scale(index);}
double LASreadOpener_get_attribute_offset(void *self, unsigned int index){
  return reinterpret_cast<const LASreadOpener *>(self)->get_attribute_offset(index);}
double LASreadOpener_get_attribute_no_data(void *self, unsigned int index){
  return reinterpret_cast<const LASreadOpener *>(self)->get_attribute_no_data(index);}
void *LASreadOpener_create(){
  return reinterpret_cast<void *>(new LASreadOpener());
}
void LASreadOpener_destroy(void *self){
  delete reinterpret_cast<LASreadOpener*>(self);
}


// LASreaderLAS
void LASreaderLAS_set_delete_stream(void *self, bool delete_stream){
  reinterpret_cast<LASreaderLAS *>(self)->set_delete_stream(delete_stream);}
bool LASreaderLAS_open(void *self, const void * file_name, int io_buffer_size, bool peek_only, unsigned int decompress_selective){
  return reinterpret_cast<LASreaderLAS *>(self)->open(
	reinterpret_cast<const char *>(file_name), io_buffer_size, peek_only, decompress_selective);}
bool LASreaderLAS_open_1(void *self, void * file, bool peek_only, unsigned int decompress_selective){
  return reinterpret_cast<LASreaderLAS *>(self)->open(
	reinterpret_cast<_IO_FILE *>(file), peek_only, decompress_selective);}
bool LASreaderLAS_open_3(void *self, void * stream, bool peek_only, unsigned int decompress_selective){
  return reinterpret_cast<LASreaderLAS *>(self)->open(
	reinterpret_cast<ByteStreamIn *>(stream), peek_only, decompress_selective);}
int LASreaderLAS_get_format(void *self){
  return reinterpret_cast<const LASreaderLAS *>(self)->get_format();}
bool LASreaderLAS_seek(void *self, const long long p_index){
  return reinterpret_cast<LASreaderLAS *>(self)->seek(p_index);}
void * LASreaderLAS_get_stream(void *self){
  return reinterpret_cast<void * >(reinterpret_cast<const LASreaderLAS *>(self)->get_stream());}
void LASreaderLAS_close(void *self, bool close_stream){
  reinterpret_cast<LASreaderLAS *>(self)->close(close_stream);}
void *LASreaderLAS_create(){
  return reinterpret_cast<void *>(new LASreaderLAS());
}
void LASreaderLAS_destroy(void *self){
  delete reinterpret_cast<LASreaderLAS*>(self);
}


// LASreaderLASrescale
void *LASreaderLASrescale_create(double x_scale_factor, double y_scale_factor, double z_scale_factor, bool check_for_overflow){
  return reinterpret_cast<void *>(new LASreaderLASrescale(x_scale_factor, y_scale_factor, z_scale_factor, check_for_overflow));
}


// LASreaderLASreoffset
void *LASreaderLASreoffset_create(double x_offset, double y_offset, double z_offset){
  return reinterpret_cast<void *>(new LASreaderLASreoffset(x_offset, y_offset, z_offset));
}
void *LASreaderLASreoffset_create_1(){
  return reinterpret_cast<void *>(new LASreaderLASreoffset());
}


// LASreaderLASrescalereoffset
void *LASreaderLASrescalereoffset_create(double x_scale_factor, double y_scale_factor, double z_scale_factor, double x_offset, double y_offset, double z_offset){
  return reinterpret_cast<void *>(new LASreaderLASrescalereoffset(x_scale_factor, y_scale_factor, z_scale_factor, x_offset, y_offset, z_offset));
}
void *LASreaderLASrescalereoffset_create_1(double x_scale_factor, double y_scale_factor, double z_scale_factor){
  return reinterpret_cast<void *>(new LASreaderLASrescalereoffset(x_scale_factor, y_scale_factor, z_scale_factor));
}
#ifdef __cplusplus
}
#endif
