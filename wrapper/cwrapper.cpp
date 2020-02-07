#include "cwrapper.h"
#include "lasreader_las.hpp"

#ifdef __cplusplus
extern "C"{
#endif
WLASvlr_lastiling* LASvlr_lastiling_create(){
    return reinterpret_cast<WLASvlr_lastiling*>( new LASvlr_lastiling());
}
WLASvlr_lasoriginal* LASvlr_lasoriginal_create(){
    return reinterpret_cast<WLASvlr_lasoriginal*>( new LASvlr_lasoriginal());
}
_Bool LASitem_is_type(WLASitem* self, LASitem::Type t){
    return reinterpret_cast<LASitem*>(self)->is_type(t);
}
const char * LASitem_get_name(WLASitem* self){
    return reinterpret_cast<LASitem*>(self)->get_name();
}
_Bool LASzip_check_compressor(WLASzip* self, const unsigned short compressor){
    return reinterpret_cast<LASzip*>(self)->check_compressor(compressor);
}
_Bool LASzip_check_coder(WLASzip* self, const unsigned short coder){
    return reinterpret_cast<LASzip*>(self)->check_coder(coder);
}
_Bool LASzip_check_item(WLASzip* self, WLASitem* item){
    return reinterpret_cast<LASzip*>(self)->check_item(reinterpret_cast<LASitem*>(item));
}
_Bool LASzip_check_items(WLASzip* self, const unsigned short num_items, WLASitem* items, const unsigned short point_size){
    return reinterpret_cast<LASzip*>(self)->check_items(num_items, reinterpret_cast<LASitem*>(items), point_size);
}
_Bool LASzip_check(WLASzip* self, const unsigned short point_size){
    return reinterpret_cast<LASzip*>(self)->check(point_size);
}
_Bool LASzip_setup(WLASzip* self, unsigned short * num_items, class LASitem ** items, const unsigned char point_type, const unsigned short point_size, const unsigned short compressor){
    return reinterpret_cast<LASzip*>(self)->setup(num_items, items, point_type, point_size, compressor);
}
_Bool LASzip_is_standard(WLASzip* self, const unsigned short num_items, WLASitem* items, unsigned char * point_type, unsigned short * record_length){
    return reinterpret_cast<LASzip*>(self)->is_standard(num_items, reinterpret_cast<LASitem*>(items), point_type, record_length);
}
_Bool LASzip_is_standard_1(WLASzip* self, unsigned char * point_type, unsigned short * record_length){
    return reinterpret_cast<LASzip*>(self)->is_standard(point_type, record_length);
}
_Bool LASzip_unpack(WLASzip* self, const unsigned char * bytes, const int num){
    return reinterpret_cast<LASzip*>(self)->unpack(bytes, num);
}
_Bool LASzip_pack(WLASzip* self, unsigned char *& bytes, int & num){
    return reinterpret_cast<LASzip*>(self)->pack(bytes, num);
}
_Bool LASzip_request_compatibility_mode(WLASzip* self, const unsigned short requested_compatibility_mode){
    return reinterpret_cast<LASzip*>(self)->request_compatibility_mode(requested_compatibility_mode);
}
_Bool LASzip_setup_1(WLASzip* self, const unsigned char point_type, const unsigned short point_size, const unsigned short compressor){
    return reinterpret_cast<LASzip*>(self)->setup(point_type, point_size, compressor);
}
_Bool LASzip_setup_2(WLASzip* self, const unsigned short num_items, WLASitem* items, const unsigned short compressor){
    return reinterpret_cast<LASzip*>(self)->setup(num_items, reinterpret_cast<LASitem*>(items), compressor);
}
_Bool LASzip_set_chunk_size(WLASzip* self, const unsigned int chunk_size){
    return reinterpret_cast<LASzip*>(self)->set_chunk_size(chunk_size);
}
_Bool LASzip_request_version(WLASzip* self, const unsigned short requested_version){
    return reinterpret_cast<LASzip*>(self)->request_version(requested_version);
}
const char * LASzip_get_error(WLASzip* self){
    return reinterpret_cast<LASzip*>(self)->get_error();
}
WLASzip* LASzip_create(){
    return reinterpret_cast<WLASzip*>( new LASzip());
}
void LASzip_destroy(WLASzip* self){
     delete reinterpret_cast<LASzip*>(self);
}
F64 LASquantizer_get_x(WLASquantizer* self, const I32 X){
    return reinterpret_cast<LASquantizer*>(self)->get_x(X);
}
F64 LASquantizer_get_y(WLASquantizer* self, const I32 Y){
    return reinterpret_cast<LASquantizer*>(self)->get_y(Y);
}
F64 LASquantizer_get_z(WLASquantizer* self, const I32 Z){
    return reinterpret_cast<LASquantizer*>(self)->get_z(Z);
}
I64 LASquantizer_get_X(WLASquantizer* self, const F64 x){
    return reinterpret_cast<LASquantizer*>(self)->get_X(x);
}
I64 LASquantizer_get_Y(WLASquantizer* self, const F64 y){
    return reinterpret_cast<LASquantizer*>(self)->get_Y(y);
}
I64 LASquantizer_get_Z(WLASquantizer* self, const F64 z){
    return reinterpret_cast<LASquantizer*>(self)->get_Z(z);
}
WLASquantizer* LASquantizer_create(){
    return reinterpret_cast<WLASquantizer*>( new LASquantizer());
}
WLASattribute* LASattribute_create(U8 size){
    return reinterpret_cast<WLASattribute*>( new LASattribute(size));
}
WLASattribute* LASattribute_create_1(U32 type, const CHAR * name, const CHAR * description){
    return reinterpret_cast<WLASattribute*>( new LASattribute(type, name, description));
}
BOOL LASattribute_set_no_data(WLASattribute* self, U8 no_data){
    return reinterpret_cast<LASattribute*>(self)->set_no_data(no_data);
}
BOOL LASattribute_set_no_data_1(WLASattribute* self, I8 no_data){
    return reinterpret_cast<LASattribute*>(self)->set_no_data(no_data);
}
BOOL LASattribute_set_no_data_2(WLASattribute* self, U16 no_data){
    return reinterpret_cast<LASattribute*>(self)->set_no_data(no_data);
}
BOOL LASattribute_set_no_data_3(WLASattribute* self, I16 no_data){
    return reinterpret_cast<LASattribute*>(self)->set_no_data(no_data);
}
BOOL LASattribute_set_no_data_4(WLASattribute* self, U32 no_data){
    return reinterpret_cast<LASattribute*>(self)->set_no_data(no_data);
}
BOOL LASattribute_set_no_data_5(WLASattribute* self, I32 no_data){
    return reinterpret_cast<LASattribute*>(self)->set_no_data(no_data);
}
BOOL LASattribute_set_no_data_6(WLASattribute* self, U64 no_data){
    return reinterpret_cast<LASattribute*>(self)->set_no_data(no_data);
}
BOOL LASattribute_set_no_data_7(WLASattribute* self, I64 no_data){
    return reinterpret_cast<LASattribute*>(self)->set_no_data(no_data);
}
BOOL LASattribute_set_no_data_8(WLASattribute* self, F32 no_data){
    return reinterpret_cast<LASattribute*>(self)->set_no_data(no_data);
}
BOOL LASattribute_set_no_data_9(WLASattribute* self, F64 no_data){
    return reinterpret_cast<LASattribute*>(self)->set_no_data(no_data);
}
void LASattribute_set_min(WLASattribute* self, U8 * min){
    reinterpret_cast<LASattribute*>(self)->set_min(min);
}
void LASattribute_update_min(WLASattribute* self, U8 * min){
    reinterpret_cast<LASattribute*>(self)->update_min(min);
}
BOOL LASattribute_set_min_1(WLASattribute* self, U8 min){
    return reinterpret_cast<LASattribute*>(self)->set_min(min);
}
BOOL LASattribute_set_min_2(WLASattribute* self, I8 min){
    return reinterpret_cast<LASattribute*>(self)->set_min(min);
}
BOOL LASattribute_set_min_3(WLASattribute* self, U16 min){
    return reinterpret_cast<LASattribute*>(self)->set_min(min);
}
BOOL LASattribute_set_min_4(WLASattribute* self, I16 min){
    return reinterpret_cast<LASattribute*>(self)->set_min(min);
}
BOOL LASattribute_set_min_5(WLASattribute* self, U32 min){
    return reinterpret_cast<LASattribute*>(self)->set_min(min);
}
BOOL LASattribute_set_min_6(WLASattribute* self, I32 min){
    return reinterpret_cast<LASattribute*>(self)->set_min(min);
}
BOOL LASattribute_set_min_7(WLASattribute* self, U64 min){
    return reinterpret_cast<LASattribute*>(self)->set_min(min);
}
BOOL LASattribute_set_min_8(WLASattribute* self, I64 min){
    return reinterpret_cast<LASattribute*>(self)->set_min(min);
}
BOOL LASattribute_set_min_9(WLASattribute* self, F32 min){
    return reinterpret_cast<LASattribute*>(self)->set_min(min);
}
BOOL LASattribute_set_min_10(WLASattribute* self, F64 min){
    return reinterpret_cast<LASattribute*>(self)->set_min(min);
}
void LASattribute_set_max(WLASattribute* self, U8 * max){
    reinterpret_cast<LASattribute*>(self)->set_max(max);
}
void LASattribute_update_max(WLASattribute* self, U8 * max){
    reinterpret_cast<LASattribute*>(self)->update_max(max);
}
BOOL LASattribute_set_max_1(WLASattribute* self, U8 max){
    return reinterpret_cast<LASattribute*>(self)->set_max(max);
}
BOOL LASattribute_set_max_2(WLASattribute* self, I8 max){
    return reinterpret_cast<LASattribute*>(self)->set_max(max);
}
BOOL LASattribute_set_max_3(WLASattribute* self, U16 max){
    return reinterpret_cast<LASattribute*>(self)->set_max(max);
}
BOOL LASattribute_set_max_4(WLASattribute* self, I16 max){
    return reinterpret_cast<LASattribute*>(self)->set_max(max);
}
BOOL LASattribute_set_max_5(WLASattribute* self, U32 max){
    return reinterpret_cast<LASattribute*>(self)->set_max(max);
}
BOOL LASattribute_set_max_6(WLASattribute* self, I32 max){
    return reinterpret_cast<LASattribute*>(self)->set_max(max);
}
BOOL LASattribute_set_max_7(WLASattribute* self, U64 max){
    return reinterpret_cast<LASattribute*>(self)->set_max(max);
}
BOOL LASattribute_set_max_8(WLASattribute* self, I64 max){
    return reinterpret_cast<LASattribute*>(self)->set_max(max);
}
BOOL LASattribute_set_max_9(WLASattribute* self, F32 max){
    return reinterpret_cast<LASattribute*>(self)->set_max(max);
}
BOOL LASattribute_set_max_10(WLASattribute* self, F64 max){
    return reinterpret_cast<LASattribute*>(self)->set_max(max);
}
BOOL LASattribute_set_scale(WLASattribute* self, F64 scale){
    return reinterpret_cast<LASattribute*>(self)->set_scale(scale);
}
BOOL LASattribute_set_offset(WLASattribute* self, F64 offset){
    return reinterpret_cast<LASattribute*>(self)->set_offset(offset);
}
BOOL LASattribute_unset_scale(WLASattribute* self){
    return reinterpret_cast<LASattribute*>(self)->unset_scale();
}
BOOL LASattribute_unset_offset(WLASattribute* self){
    return reinterpret_cast<LASattribute*>(self)->unset_offset();
}
BOOL LASattribute_has_no_data(WLASattribute* self){
    return reinterpret_cast<LASattribute*>(self)->has_no_data();
}
BOOL LASattribute_has_min(WLASattribute* self){
    return reinterpret_cast<LASattribute*>(self)->has_min();
}
BOOL LASattribute_has_max(WLASattribute* self){
    return reinterpret_cast<LASattribute*>(self)->has_max();
}
BOOL LASattribute_has_scale(WLASattribute* self){
    return reinterpret_cast<LASattribute*>(self)->has_scale();
}
BOOL LASattribute_has_offset(WLASattribute* self){
    return reinterpret_cast<LASattribute*>(self)->has_offset();
}
U32 LASattribute_get_size(WLASattribute* self){
    return reinterpret_cast<LASattribute*>(self)->get_size();
}
F64 LASattribute_get_value_as_float(WLASattribute* self, U8 * pointer){
    return reinterpret_cast<LASattribute*>(self)->get_value_as_float(pointer);
}
void LASattribute_set_value_as_float(WLASattribute* self, U8 * pointer, F64 value){
    reinterpret_cast<LASattribute*>(self)->set_value_as_float(pointer, value);
}
WLASattributer* LASattributer_create(){
    return reinterpret_cast<WLASattributer*>( new LASattributer());
}
void LASattributer_destroy(WLASattributer* self){
     delete reinterpret_cast<LASattributer*>(self);
}
void LASattributer_clean_attributes(WLASattributer* self){
    reinterpret_cast<LASattributer*>(self)->clean_attributes();
}
BOOL LASattributer_init_attributes(WLASattributer* self, U32 number_attributes, WLASattribute* attributes){
    return reinterpret_cast<LASattributer*>(self)->init_attributes(number_attributes, reinterpret_cast<LASattribute*>(attributes));
}
I32 LASattributer_add_attribute(WLASattributer* self, WLASattribute* attribute){
    return reinterpret_cast<LASattributer*>(self)->add_attribute(*reinterpret_cast<LASattribute*>(attribute));
}
I16 LASattributer_get_attributes_size(WLASattributer* self){
    return reinterpret_cast<LASattributer*>(self)->get_attributes_size();
}
I32 LASattributer_get_attribute_index(WLASattributer* self, const CHAR * name){
    return reinterpret_cast<LASattributer*>(self)->get_attribute_index(name);
}
I32 LASattributer_get_attribute_start(WLASattributer* self, const CHAR * name){
    return reinterpret_cast<LASattributer*>(self)->get_attribute_start(name);
}
I32 LASattributer_get_attribute_start_1(WLASattributer* self, I32 index){
    return reinterpret_cast<LASattributer*>(self)->get_attribute_start(index);
}
I32 LASattributer_get_attribute_size(WLASattributer* self, I32 index){
    return reinterpret_cast<LASattributer*>(self)->get_attribute_size(index);
}
const CHAR * LASattributer_get_attribute_name(WLASattributer* self, I32 index){
    return reinterpret_cast<LASattributer*>(self)->get_attribute_name(index);
}
BOOL LASattributer_remove_attribute(WLASattributer* self, I32 index){
    return reinterpret_cast<LASattributer*>(self)->remove_attribute(index);
}
BOOL LASattributer_remove_attribute_1(WLASattributer* self, const CHAR * name){
    return reinterpret_cast<LASattributer*>(self)->remove_attribute(name);
}
WLASwavepacket* LASwavepacket_create(){
    return reinterpret_cast<WLASwavepacket*>( new LASwavepacket());
}
void LASwavepacket_zero(WLASwavepacket* self){
    reinterpret_cast<LASwavepacket*>(self)->zero();
}
U8 LASwavepacket_getIndex(WLASwavepacket* self){
    return reinterpret_cast<LASwavepacket*>(self)->getIndex();
}
U64 LASwavepacket_getOffset(WLASwavepacket* self){
    return reinterpret_cast<LASwavepacket*>(self)->getOffset();
}
U32 LASwavepacket_getSize(WLASwavepacket* self){
    return reinterpret_cast<LASwavepacket*>(self)->getSize();
}
F32 LASwavepacket_getLocation(WLASwavepacket* self){
    return reinterpret_cast<LASwavepacket*>(self)->getLocation();
}
F32 LASwavepacket_getXt(WLASwavepacket* self){
    return reinterpret_cast<LASwavepacket*>(self)->getXt();
}
F32 LASwavepacket_getYt(WLASwavepacket* self){
    return reinterpret_cast<LASwavepacket*>(self)->getYt();
}
F32 LASwavepacket_getZt(WLASwavepacket* self){
    return reinterpret_cast<LASwavepacket*>(self)->getZt();
}
void LASwavepacket_setIndex(WLASwavepacket* self, U8 index){
    reinterpret_cast<LASwavepacket*>(self)->setIndex(index);
}
void LASwavepacket_setOffset(WLASwavepacket* self, U64 offset){
    reinterpret_cast<LASwavepacket*>(self)->setOffset(offset);
}
void LASwavepacket_setSize(WLASwavepacket* self, U32 size){
    reinterpret_cast<LASwavepacket*>(self)->setSize(size);
}
void LASwavepacket_setLocation(WLASwavepacket* self, F32 location){
    reinterpret_cast<LASwavepacket*>(self)->setLocation(location);
}
void LASwavepacket_setXt(WLASwavepacket* self, F32 xt){
    reinterpret_cast<LASwavepacket*>(self)->setXt(xt);
}
void LASwavepacket_setYt(WLASwavepacket* self, F32 yt){
    reinterpret_cast<LASwavepacket*>(self)->setYt(yt);
}
void LASwavepacket_setZt(WLASwavepacket* self, F32 zt){
    reinterpret_cast<LASwavepacket*>(self)->setZt(zt);
}
void LASwavepacket_flipDirection(WLASwavepacket* self){
    reinterpret_cast<LASwavepacket*>(self)->flipDirection();
}
void LASpoint_copy_to(WLASpoint* self, U8 * buffer){
    reinterpret_cast<LASpoint*>(self)->copy_to(buffer);
}
void LASpoint_copy_from(WLASpoint* self, const U8 * buffer){
    reinterpret_cast<LASpoint*>(self)->copy_from(buffer);
}
BOOL LASpoint_init(WLASpoint* self, WLASquantizer* quantizer, const U8 point_type, const U16 point_size, WLASattributer* attributer){
    return reinterpret_cast<LASpoint*>(self)->init(reinterpret_cast<LASquantizer*>(quantizer), point_type, point_size, reinterpret_cast<LASattributer*>(attributer));
}
BOOL LASpoint_init_1(WLASpoint* self, WLASquantizer* quantizer, const U32 num_items, WLASitem* items, WLASattributer* attributer){
    return reinterpret_cast<LASpoint*>(self)->init(reinterpret_cast<LASquantizer*>(quantizer), num_items, reinterpret_cast<LASitem*>(items), reinterpret_cast<LASattributer*>(attributer));
}
BOOL LASpoint_inside_rectangle(WLASpoint* self, const F64 r_min_x, const F64 r_min_y, const F64 r_max_x, const F64 r_max_y){
    return reinterpret_cast<LASpoint*>(self)->inside_rectangle(r_min_x, r_min_y, r_max_x, r_max_y);
}
BOOL LASpoint_inside_tile(WLASpoint* self, const F32 ll_x, const F32 ll_y, const F32 ur_x, const F32 ur_y){
    return reinterpret_cast<LASpoint*>(self)->inside_tile(ll_x, ll_y, ur_x, ur_y);
}
BOOL LASpoint_inside_circle(WLASpoint* self, const F64 center_x, const F64 center_y, F64 squared_radius){
    return reinterpret_cast<LASpoint*>(self)->inside_circle(center_x, center_y, squared_radius);
}
BOOL LASpoint_inside_box(WLASpoint* self, const F64 min_x, const F64 min_y, const F64 min_z, const F64 max_x, const F64 max_y, const F64 max_z){
    return reinterpret_cast<LASpoint*>(self)->inside_box(min_x, min_y, min_z, max_x, max_y, max_z);
}
BOOL LASpoint_inside_bounding_box(WLASpoint* self, const F64 min_x, const F64 min_y, const F64 min_z, const F64 max_x, const F64 max_y, const F64 max_z){
    return reinterpret_cast<LASpoint*>(self)->inside_bounding_box(min_x, min_y, min_z, max_x, max_y, max_z);
}
BOOL LASpoint_is_zero(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->is_zero();
}
void LASpoint_zero(WLASpoint* self){
    reinterpret_cast<LASpoint*>(self)->zero();
}
void LASpoint_clean(WLASpoint* self){
    reinterpret_cast<LASpoint*>(self)->clean();
}
WLASpoint* LASpoint_create(){
    return reinterpret_cast<WLASpoint*>( new LASpoint());
}
BOOL LASpoint_is_first(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->is_first();
}
BOOL LASpoint_is_intermediate(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->is_intermediate();
}
BOOL LASpoint_is_last(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->is_last();
}
BOOL LASpoint_is_single(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->is_single();
}
BOOL LASpoint_is_first_of_many(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->is_first_of_many();
}
BOOL LASpoint_is_last_of_many(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->is_last_of_many();
}
I32 LASpoint_get_X(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_X();
}
I32 LASpoint_get_Y(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_Y();
}
I32 LASpoint_get_Z(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_Z();
}
U16 LASpoint_get_intensity(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_intensity();
}
U8 LASpoint_get_return_number(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_return_number();
}
U8 LASpoint_get_number_of_returns(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_number_of_returns();
}
U8 LASpoint_get_scan_direction_flag(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_scan_direction_flag();
}
U8 LASpoint_get_edge_of_flight_line(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_edge_of_flight_line();
}
U8 LASpoint_get_classification(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_classification();
}
U8 LASpoint_get_synthetic_flag(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_synthetic_flag();
}
U8 LASpoint_get_keypoint_flag(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_keypoint_flag();
}
U8 LASpoint_get_withheld_flag(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_withheld_flag();
}
I8 LASpoint_get_scan_angle_rank(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_scan_angle_rank();
}
U8 LASpoint_get_user_data(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_user_data();
}
U16 LASpoint_get_point_source_ID(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_point_source_ID();
}
U8 LASpoint_get_deleted_flag(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_deleted_flag();
}
F64 LASpoint_get_gps_time(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_gps_time();
}
const U16 * LASpoint_get_RGB(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_RGB();
}
const U16 * LASpoint_get_RGBI(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_RGBI();
}
U16 LASpoint_get_RGBI_1(WLASpoint* self, const U32 band){
    return reinterpret_cast<LASpoint*>(self)->get_RGBI(band);
}
U16 LASpoint_get_R(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_R();
}
U16 LASpoint_get_G(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_G();
}
U16 LASpoint_get_B(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_B();
}
U16 LASpoint_get_I(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_I();
}
U16 LASpoint_get_NIR(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_NIR();
}
void LASpoint_set_X(WLASpoint* self, const I32 X){
    reinterpret_cast<LASpoint*>(self)->set_X(X);
}
void LASpoint_set_Y(WLASpoint* self, const I32 Y){
    reinterpret_cast<LASpoint*>(self)->set_Y(Y);
}
void LASpoint_set_Z(WLASpoint* self, const I32 Z){
    reinterpret_cast<LASpoint*>(self)->set_Z(Z);
}
void LASpoint_set_intensity(WLASpoint* self, const U16 intensity){
    reinterpret_cast<LASpoint*>(self)->set_intensity(intensity);
}
void LASpoint_set_return_number(WLASpoint* self, const U8 return_number){
    reinterpret_cast<LASpoint*>(self)->set_return_number(return_number);
}
void LASpoint_set_number_of_returns(WLASpoint* self, const U8 number_of_returns){
    reinterpret_cast<LASpoint*>(self)->set_number_of_returns(number_of_returns);
}
void LASpoint_set_scan_direction_flag(WLASpoint* self, const U8 scan_direction_flag){
    reinterpret_cast<LASpoint*>(self)->set_scan_direction_flag(scan_direction_flag);
}
void LASpoint_set_edge_of_flight_line(WLASpoint* self, const U8 edge_of_flight_line){
    reinterpret_cast<LASpoint*>(self)->set_edge_of_flight_line(edge_of_flight_line);
}
void LASpoint_set_classification(WLASpoint* self, U8 classification){
    reinterpret_cast<LASpoint*>(self)->set_classification(classification);
}
void LASpoint_set_synthetic_flag(WLASpoint* self, U8 synthetic_flag){
    reinterpret_cast<LASpoint*>(self)->set_synthetic_flag(synthetic_flag);
}
void LASpoint_set_keypoint_flag(WLASpoint* self, U8 keypoint_flag){
    reinterpret_cast<LASpoint*>(self)->set_keypoint_flag(keypoint_flag);
}
void LASpoint_set_withheld_flag(WLASpoint* self, U8 withheld_flag){
    reinterpret_cast<LASpoint*>(self)->set_withheld_flag(withheld_flag);
}
void LASpoint_set_scan_angle_rank(WLASpoint* self, I8 scan_angle_rank){
    reinterpret_cast<LASpoint*>(self)->set_scan_angle_rank(scan_angle_rank);
}
void LASpoint_set_user_data(WLASpoint* self, U8 user_data){
    reinterpret_cast<LASpoint*>(self)->set_user_data(user_data);
}
void LASpoint_set_point_source_ID(WLASpoint* self, U16 point_source_ID){
    reinterpret_cast<LASpoint*>(self)->set_point_source_ID(point_source_ID);
}
void LASpoint_set_deleted_flag(WLASpoint* self, U8 deleted_flag){
    reinterpret_cast<LASpoint*>(self)->set_deleted_flag(deleted_flag);
}
void LASpoint_set_gps_time(WLASpoint* self, const F64 gps_time){
    reinterpret_cast<LASpoint*>(self)->set_gps_time(gps_time);
}
void LASpoint_set_RGB(WLASpoint* self, const U16 * rgb){
    reinterpret_cast<LASpoint*>(self)->set_RGB(rgb);
}
void LASpoint_set_RGBI(WLASpoint* self, const U16 * rgb){
    reinterpret_cast<LASpoint*>(self)->set_RGBI(rgb);
}
void LASpoint_set_RGBI_1(WLASpoint* self, const U32 band, const U16 value){
    reinterpret_cast<LASpoint*>(self)->set_RGBI(band, value);
}
void LASpoint_set_R(WLASpoint* self, const U16 R){
    reinterpret_cast<LASpoint*>(self)->set_R(R);
}
void LASpoint_set_G(WLASpoint* self, const U16 G){
    reinterpret_cast<LASpoint*>(self)->set_G(G);
}
void LASpoint_set_B(WLASpoint* self, const U16 B){
    reinterpret_cast<LASpoint*>(self)->set_B(B);
}
void LASpoint_set_I(WLASpoint* self, const U16 I){
    reinterpret_cast<LASpoint*>(self)->set_I(I);
}
void LASpoint_set_NIR(WLASpoint* self, const U16 NIR){
    reinterpret_cast<LASpoint*>(self)->set_NIR(NIR);
}
F64 LASpoint_get_x(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_x();
}
F64 LASpoint_get_y(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_y();
}
F64 LASpoint_get_z(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_z();
}
BOOL LASpoint_set_x(WLASpoint* self, const F64 x){
    return reinterpret_cast<LASpoint*>(self)->set_x(x);
}
BOOL LASpoint_set_y(WLASpoint* self, const F64 y){
    return reinterpret_cast<LASpoint*>(self)->set_y(y);
}
BOOL LASpoint_set_z(WLASpoint* self, const F64 z){
    return reinterpret_cast<LASpoint*>(self)->set_z(z);
}
BOOL LASpoint_is_extended_point_type(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->is_extended_point_type();
}
U8 LASpoint_get_extended_classification(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_extended_classification();
}
U8 LASpoint_get_extended_return_number(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_extended_return_number();
}
U8 LASpoint_get_extended_number_of_returns(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_extended_number_of_returns();
}
I16 LASpoint_get_extended_scan_angle(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_extended_scan_angle();
}
U8 LASpoint_get_extended_overlap_flag(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_extended_overlap_flag();
}
U8 LASpoint_get_extended_scanner_channel(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_extended_scanner_channel();
}
void LASpoint_set_extended_classification(WLASpoint* self, U8 extended_classification){
    reinterpret_cast<LASpoint*>(self)->set_extended_classification(extended_classification);
}
void LASpoint_set_extended_return_number(WLASpoint* self, U8 extended_return_number){
    reinterpret_cast<LASpoint*>(self)->set_extended_return_number(extended_return_number);
}
void LASpoint_set_extended_number_of_returns(WLASpoint* self, U8 extended_number_of_returns){
    reinterpret_cast<LASpoint*>(self)->set_extended_number_of_returns(extended_number_of_returns);
}
void LASpoint_set_extended_scan_angle(WLASpoint* self, I16 extended_scan_angle){
    reinterpret_cast<LASpoint*>(self)->set_extended_scan_angle(extended_scan_angle);
}
void LASpoint_set_extended_overlap_flag(WLASpoint* self, U8 extended_overlap_flag){
    reinterpret_cast<LASpoint*>(self)->set_extended_overlap_flag(extended_overlap_flag);
}
void LASpoint_set_extended_scanner_channel(WLASpoint* self, U8 extended_scanner_channel){
    reinterpret_cast<LASpoint*>(self)->set_extended_scanner_channel(extended_scanner_channel);
}
F32 LASpoint_get_scan_angle(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_scan_angle();
}
F32 LASpoint_get_abs_scan_angle(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->get_abs_scan_angle();
}
void LASpoint_set_scan_angle(WLASpoint* self, F32 scan_angle){
    reinterpret_cast<LASpoint*>(self)->set_scan_angle(scan_angle);
}
void LASpoint_compute_coordinates(WLASpoint* self){
    reinterpret_cast<LASpoint*>(self)->compute_coordinates();
}
BOOL LASpoint_compute_XYZ(WLASpoint* self){
    return reinterpret_cast<LASpoint*>(self)->compute_XYZ();
}
BOOL LASpoint_compute_XYZ_1(WLASpoint* self, WLASquantizer* quantizer){
    return reinterpret_cast<LASpoint*>(self)->compute_XYZ(reinterpret_cast<LASquantizer*>(quantizer));
}
BOOL LASpoint_has_attribute(WLASpoint* self, U32 index){
    return reinterpret_cast<LASpoint*>(self)->has_attribute(index);
}
BOOL LASpoint_get_attribute(WLASpoint* self, U32 index, U8 * data){
    return reinterpret_cast<LASpoint*>(self)->get_attribute(index, data);
}
BOOL LASpoint_set_attribute(WLASpoint* self, U32 index, const U8 * data){
    return reinterpret_cast<LASpoint*>(self)->set_attribute(index, data);
}
const CHAR * LASpoint_get_attribute_name(WLASpoint* self, U32 index){
    return reinterpret_cast<LASpoint*>(self)->get_attribute_name(index);
}
F64 LASpoint_get_attribute_as_float(WLASpoint* self, U32 index){
    return reinterpret_cast<LASpoint*>(self)->get_attribute_as_float(index);
}
void LASpoint_set_attribute_as_float(WLASpoint* self, U32 index, F64 value){
    reinterpret_cast<LASpoint*>(self)->set_attribute_as_float(index, value);
}
void LASpoint_get_attribute_1(WLASpoint* self, I32 start, U8 & data){
    reinterpret_cast<LASpoint*>(self)->get_attribute(start, data);
}
void LASpoint_set_attribute_1(WLASpoint* self, I32 start, U8 data){
    reinterpret_cast<LASpoint*>(self)->set_attribute(start, data);
}
void LASpoint_get_attribute_2(WLASpoint* self, I32 start, I8 & data){
    reinterpret_cast<LASpoint*>(self)->get_attribute(start, data);
}
void LASpoint_set_attribute_2(WLASpoint* self, I32 start, I8 data){
    reinterpret_cast<LASpoint*>(self)->set_attribute(start, data);
}
void LASpoint_get_attribute_3(WLASpoint* self, I32 start, U16 & data){
    reinterpret_cast<LASpoint*>(self)->get_attribute(start, data);
}
void LASpoint_set_attribute_3(WLASpoint* self, I32 start, U16 data){
    reinterpret_cast<LASpoint*>(self)->set_attribute(start, data);
}
void LASpoint_get_attribute_4(WLASpoint* self, I32 start, I16 & data){
    reinterpret_cast<LASpoint*>(self)->get_attribute(start, data);
}
void LASpoint_set_attribute_4(WLASpoint* self, I32 start, I16 data){
    reinterpret_cast<LASpoint*>(self)->set_attribute(start, data);
}
void LASpoint_get_attribute_5(WLASpoint* self, I32 start, U32 & data){
    reinterpret_cast<LASpoint*>(self)->get_attribute(start, data);
}
void LASpoint_set_attribute_5(WLASpoint* self, I32 start, U32 data){
    reinterpret_cast<LASpoint*>(self)->set_attribute(start, data);
}
void LASpoint_get_attribute_6(WLASpoint* self, I32 start, I32 & data){
    reinterpret_cast<LASpoint*>(self)->get_attribute(start, data);
}
void LASpoint_set_attribute_6(WLASpoint* self, I32 start, I32 data){
    reinterpret_cast<LASpoint*>(self)->set_attribute(start, data);
}
void LASpoint_get_attribute_7(WLASpoint* self, I32 start, U64 & data){
    reinterpret_cast<LASpoint*>(self)->get_attribute(start, data);
}
void LASpoint_set_attribute_7(WLASpoint* self, I32 start, U64 data){
    reinterpret_cast<LASpoint*>(self)->set_attribute(start, data);
}
void LASpoint_get_attribute_8(WLASpoint* self, I32 start, I64 & data){
    reinterpret_cast<LASpoint*>(self)->get_attribute(start, data);
}
void LASpoint_set_attribute_8(WLASpoint* self, I32 start, I64 data){
    reinterpret_cast<LASpoint*>(self)->set_attribute(start, data);
}
void LASpoint_get_attribute_9(WLASpoint* self, I32 start, F32 & data){
    reinterpret_cast<LASpoint*>(self)->get_attribute(start, data);
}
void LASpoint_set_attribute_9(WLASpoint* self, I32 start, F32 data){
    reinterpret_cast<LASpoint*>(self)->set_attribute(start, data);
}
void LASpoint_get_attribute_10(WLASpoint* self, I32 start, F64 & data){
    reinterpret_cast<LASpoint*>(self)->get_attribute(start, data);
}
void LASpoint_set_attribute_10(WLASpoint* self, I32 start, F64 data){
    reinterpret_cast<LASpoint*>(self)->set_attribute(start, data);
}
void LASpoint_destroy(WLASpoint* self){
     delete reinterpret_cast<LASpoint*>(self);
}
WLASvlr* LASvlr_create(){
    return reinterpret_cast<WLASvlr*>( new LASvlr());
}
WLASevlr* LASevlr_create(){
    return reinterpret_cast<WLASevlr*>( new LASevlr());
}
WLASvlr_wave_packet_descr* LASvlr_wave_packet_descr_create(){
    return reinterpret_cast<WLASvlr_wave_packet_descr*>( new LASvlr_wave_packet_descr());
}
void LASvlr_wave_packet_descr_clean(WLASvlr_wave_packet_descr* self){
    reinterpret_cast<LASvlr_wave_packet_descr*>(self)->clean();
}
U8 LASvlr_wave_packet_descr_getBitsPerSample(WLASvlr_wave_packet_descr* self){
    return reinterpret_cast<LASvlr_wave_packet_descr*>(self)->getBitsPerSample();
}
U8 LASvlr_wave_packet_descr_getCompressionType(WLASvlr_wave_packet_descr* self){
    return reinterpret_cast<LASvlr_wave_packet_descr*>(self)->getCompressionType();
}
U32 LASvlr_wave_packet_descr_getNumberOfSamples(WLASvlr_wave_packet_descr* self){
    return reinterpret_cast<LASvlr_wave_packet_descr*>(self)->getNumberOfSamples();
}
U32 LASvlr_wave_packet_descr_getTemporalSpacing(WLASvlr_wave_packet_descr* self){
    return reinterpret_cast<LASvlr_wave_packet_descr*>(self)->getTemporalSpacing();
}
F64 LASvlr_wave_packet_descr_getDigitizerGain(WLASvlr_wave_packet_descr* self){
    return reinterpret_cast<LASvlr_wave_packet_descr*>(self)->getDigitizerGain();
}
F64 LASvlr_wave_packet_descr_getDigitizerOffset(WLASvlr_wave_packet_descr* self){
    return reinterpret_cast<LASvlr_wave_packet_descr*>(self)->getDigitizerOffset();
}
void LASvlr_wave_packet_descr_setBitsPerSample(WLASvlr_wave_packet_descr* self, U8 bps){
    reinterpret_cast<LASvlr_wave_packet_descr*>(self)->setBitsPerSample(bps);
}
void LASvlr_wave_packet_descr_setCompressionType(WLASvlr_wave_packet_descr* self, U8 compression){
    reinterpret_cast<LASvlr_wave_packet_descr*>(self)->setCompressionType(compression);
}
void LASvlr_wave_packet_descr_setNumberOfSamples(WLASvlr_wave_packet_descr* self, U32 samples){
    reinterpret_cast<LASvlr_wave_packet_descr*>(self)->setNumberOfSamples(samples);
}
void LASvlr_wave_packet_descr_setTemporalSpacing(WLASvlr_wave_packet_descr* self, U32 spacing){
    reinterpret_cast<LASvlr_wave_packet_descr*>(self)->setTemporalSpacing(spacing);
}
void LASvlr_wave_packet_descr_setDigitizerGain(WLASvlr_wave_packet_descr* self, F64 gain){
    reinterpret_cast<LASvlr_wave_packet_descr*>(self)->setDigitizerGain(gain);
}
void LASvlr_wave_packet_descr_setDigitizerOffset(WLASvlr_wave_packet_descr* self, F64 offset){
    reinterpret_cast<LASvlr_wave_packet_descr*>(self)->setDigitizerOffset(offset);
}
WLASheader* LASheader_create(){
    return reinterpret_cast<WLASheader*>( new LASheader());
}
void LASheader_set_bounding_box(WLASheader* self, F64 min_x, F64 min_y, F64 min_z, F64 max_x, F64 max_y, F64 max_z, BOOL auto_scale, BOOL auto_offset){
    reinterpret_cast<LASheader*>(self)->set_bounding_box(min_x, min_y, min_z, max_x, max_y, max_z, auto_scale, auto_offset);
}
void LASheader_set_global_encoding_bit(WLASheader* self, I32 bit){
    reinterpret_cast<LASheader*>(self)->set_global_encoding_bit(bit);
}
void LASheader_unset_global_encoding_bit(WLASheader* self, I32 bit){
    reinterpret_cast<LASheader*>(self)->unset_global_encoding_bit(bit);
}
BOOL LASheader_get_global_encoding_bit(WLASheader* self, I32 bit){
    return reinterpret_cast<LASheader*>(self)->get_global_encoding_bit(bit);
}
void LASheader_clean_las_header(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->clean_las_header();
}
void LASheader_clean_user_data_in_header(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->clean_user_data_in_header();
}
void LASheader_clean_vlrs(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->clean_vlrs();
}
void LASheader_clean_evlrs(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->clean_evlrs();
}
void LASheader_clean_laszip(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->clean_laszip();
}
void LASheader_clean_lastiling(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->clean_lastiling();
}
void LASheader_clean_lasoriginal(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->clean_lasoriginal();
}
void LASheader_clean_user_data_after_header(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->clean_user_data_after_header();
}
void LASheader_clean(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->clean();
}
void LASheader_unlink(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->unlink();
}
BOOL LASheader_check(WLASheader* self){
    return reinterpret_cast<LASheader*>(self)->check();
}
BOOL LASheader_is_compressed(WLASheader* self){
    return reinterpret_cast<LASheader*>(self)->is_compressed();
}
BOOL LASheader_is_lonlat(WLASheader* self, const F32 extend){
    return reinterpret_cast<LASheader*>(self)->is_lonlat(extend);
}
BOOL LASheader_add_vlr(WLASheader* self, const CHAR * user_id, const U16 record_id, const U16 record_length_after_header, U8 * data, const BOOL keep_description, const CHAR * description, const BOOL keep_existing){
    return reinterpret_cast<LASheader*>(self)->add_vlr(user_id, record_id, record_length_after_header, data, keep_description, description, keep_existing);
}
WLASvlr* LASheader_get_vlr(WLASheader* self, const CHAR * user_id, U16 record_id){
  return ( WLASvlr*)(reinterpret_cast<LASheader*>(self)->get_vlr(user_id, record_id));
}
BOOL LASheader_remove_vlr(WLASheader* self, U32 i, BOOL delete_data){
    return reinterpret_cast<LASheader*>(self)->remove_vlr(i, delete_data);
}
BOOL LASheader_remove_vlr_1(WLASheader* self, const CHAR * user_id, U16 record_id){
    return reinterpret_cast<LASheader*>(self)->remove_vlr(user_id, record_id);
}
void LASheader_add_evlr(WLASheader* self, const CHAR * user_id, const U16 record_id, const I64 record_length_after_header, U8 * data, const BOOL keep_description, const CHAR * description, const BOOL keep_existing){
    reinterpret_cast<LASheader*>(self)->add_evlr(user_id, record_id, record_length_after_header, data, keep_description, description, keep_existing);
}
BOOL LASheader_remove_evlr(WLASheader* self, U32 i, BOOL delete_data){
    return reinterpret_cast<LASheader*>(self)->remove_evlr(i, delete_data);
}
BOOL LASheader_remove_evlr_1(WLASheader* self, const CHAR * user_id, U16 record_id){
    return reinterpret_cast<LASheader*>(self)->remove_evlr(user_id, record_id);
}
void LASheader_set_lastiling(WLASheader* self, U32 level, U32 level_index, U32 implicit_levels, BOOL buffer, BOOL reversible, F32 min_x, F32 max_x, F32 min_y, F32 max_y){
    reinterpret_cast<LASheader*>(self)->set_lastiling(level, level_index, implicit_levels, buffer, reversible, min_x, max_x, min_y, max_y);
}
void LASheader_set_lasoriginal(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->set_lasoriginal();
}
BOOL LASheader_restore_lasoriginal(WLASheader* self){
    return reinterpret_cast<LASheader*>(self)->restore_lasoriginal();
}
BOOL LASheader_set_geo_keys(WLASheader* self, const I32 number_of_keys, WLASvlr_key_entry* geo_keys){
    return reinterpret_cast<LASheader*>(self)->set_geo_keys(number_of_keys, reinterpret_cast<LASvlr_key_entry*>(geo_keys));
}
BOOL LASheader_set_geo_double_params(WLASheader* self, const I32 num_geo_double_params, const F64 * geo_double_params){
    return reinterpret_cast<LASheader*>(self)->set_geo_double_params(num_geo_double_params, geo_double_params);
}
void LASheader_del_geo_double_params(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->del_geo_double_params();
}
BOOL LASheader_set_geo_ascii_params(WLASheader* self, const I32 num_geo_ascii_params, const CHAR * geo_ascii_params){
    return reinterpret_cast<LASheader*>(self)->set_geo_ascii_params(num_geo_ascii_params, geo_ascii_params);
}
void LASheader_del_geo_ascii_params(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->del_geo_ascii_params();
}
void LASheader_set_geo_wkt_ogc_math(WLASheader* self, const I32 num_geo_wkt_ogc_math, const CHAR * geo_wkt_ogc_math){
    reinterpret_cast<LASheader*>(self)->set_geo_wkt_ogc_math(num_geo_wkt_ogc_math, geo_wkt_ogc_math);
}
void LASheader_del_geo_wkt_ogc_math(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->del_geo_wkt_ogc_math();
}
void LASheader_set_geo_ogc_wkt(WLASheader* self, const I32 num_geo_ogc_wkt, const CHAR * geo_ogc_wkt, BOOL in_evlr){
    reinterpret_cast<LASheader*>(self)->set_geo_ogc_wkt(num_geo_ogc_wkt, geo_ogc_wkt, in_evlr);
}
void LASheader_del_geo_ogc_wkt(WLASheader* self){
    reinterpret_cast<LASheader*>(self)->del_geo_ogc_wkt();
}
BOOL LASheader_update_extra_bytes_vlr(WLASheader* self, const BOOL keep_description){
    return reinterpret_cast<LASheader*>(self)->update_extra_bytes_vlr(keep_description);
}
void LASheader_destroy(WLASheader* self){
     delete reinterpret_cast<LASheader*>(self);
}
void LASignore_usage(WLASignore* self){
    reinterpret_cast<LASignore*>(self)->usage();
}
void LASignore_ignore_class(WLASignore* self, U8 classification){
    reinterpret_cast<LASignore*>(self)->ignore_class(classification);
}
void LASignore_dont_ignore_class(WLASignore* self, U8 classification){
    reinterpret_cast<LASignore*>(self)->dont_ignore_class(classification);
}
BOOL LASignore_parse(WLASignore* self, int & i, int argc, char ** argv){
    return reinterpret_cast<LASignore*>(self)->parse(i, argc, argv);
}
I32 LASignore_unparse(WLASignore* self, CHAR * string){
    return reinterpret_cast<LASignore*>(self)->unparse(string);
}
BOOL LASignore_parse_1(WLASignore* self, U32 curr_parameter, const U32 num_parameters, const F64 * parameters){
    return reinterpret_cast<LASignore*>(self)->parse(curr_parameter, num_parameters, parameters);
}
void LASignore_unparse_1(WLASignore* self, U32 & num_parameters, F64 * parameters){
    reinterpret_cast<LASignore*>(self)->unparse(num_parameters, parameters);
}
U32 LASignore_get_decompress_selective(WLASignore* self){
    return reinterpret_cast<LASignore*>(self)->get_decompress_selective();
}
BOOL LASignore_ignore(WLASignore* self, WLASpoint* point){
    return reinterpret_cast<LASignore*>(self)->ignore(reinterpret_cast<LASpoint*>(point));
}
WLASignore* LASignore_create(){
    return reinterpret_cast<WLASignore*>( new LASignore());
}
void LASignore_destroy(WLASignore* self){
     delete reinterpret_cast<LASignore*>(self);
}
I32 LASreader_get_format(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_format();
}
BOOL LASreader_has_layers(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->has_layers();
}
void LASreader_set_index(WLASreader* self, WLASindex* index){
    reinterpret_cast<LASreader*>(self)->set_index(reinterpret_cast<LASindex*>(index));
}
WLASindex* LASreader_get_index(WLASreader* self){
    return reinterpret_cast<WLASindex*>(reinterpret_cast<LASreader*>(self)->get_index());
}
void LASreader_set_filter(WLASreader* self, WLASfilter* filter){
    reinterpret_cast<LASreader*>(self)->set_filter(reinterpret_cast<LASfilter*>(filter));
}
WLASfilter* LASreader_get_filter(WLASreader* self){
    return reinterpret_cast<WLASfilter*>(reinterpret_cast<LASreader*>(self)->get_filter());
}
void LASreader_set_transform(WLASreader* self, WLAStransform* transform){
    reinterpret_cast<LASreader*>(self)->set_transform(reinterpret_cast<LAStransform*>(transform));
}
WLAStransform* LASreader_get_transform(WLASreader* self){
    return reinterpret_cast<WLAStransform*>(reinterpret_cast<LASreader*>(self)->get_transform());
}
void LASreader_set_ignore(WLASreader* self, WLASignore* ignore){
    reinterpret_cast<LASreader*>(self)->set_ignore(reinterpret_cast<LASignore*>(ignore));
}
WLASignore* LASreader_get_ignore(WLASreader* self){
    return reinterpret_cast<WLASignore*>(reinterpret_cast<LASreader*>(self)->get_ignore());
}
U32 LASreader_get_inside(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_inside();
}
BOOL LASreader_inside_none(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->inside_none();
}
BOOL LASreader_inside_tile(WLASreader* self, const F32 ll_x, const F32 ll_y, const F32 size){
    return reinterpret_cast<LASreader*>(self)->inside_tile(ll_x, ll_y, size);
}
F32 LASreader_get_t_ll_x(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_t_ll_x();
}
F32 LASreader_get_t_ll_y(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_t_ll_y();
}
F32 LASreader_get_t_size(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_t_size();
}
BOOL LASreader_inside_circle(WLASreader* self, const F64 center_x, const F64 center_y, const F64 radius){
    return reinterpret_cast<LASreader*>(self)->inside_circle(center_x, center_y, radius);
}
F64 LASreader_get_c_center_x(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_c_center_x();
}
F64 LASreader_get_c_center_y(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_c_center_y();
}
F64 LASreader_get_c_radius(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_c_radius();
}
BOOL LASreader_inside_rectangle(WLASreader* self, const F64 min_x, const F64 min_y, const F64 max_x, const F64 max_y){
    return reinterpret_cast<LASreader*>(self)->inside_rectangle(min_x, min_y, max_x, max_y);
}
F64 LASreader_get_r_min_x(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_r_min_x();
}
F64 LASreader_get_r_min_y(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_r_min_y();
}
F64 LASreader_get_r_max_x(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_r_max_x();
}
F64 LASreader_get_r_max_y(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_r_max_y();
}
BOOL LASreader_seek(WLASreader* self, const I64 p_index){
    return reinterpret_cast<LASreader*>(self)->seek(p_index);
}
BOOL LASreader_read_point(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->read_point();
}
BOOL LASreader_ignore_point(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->ignore_point();
}
void LASreader_compute_coordinates(WLASreader* self){
    reinterpret_cast<LASreader*>(self)->compute_coordinates();
}
F64 LASreader_get_min_x(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_min_x();
}
F64 LASreader_get_min_y(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_min_y();
}
F64 LASreader_get_min_z(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_min_z();
}
F64 LASreader_get_max_x(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_max_x();
}
F64 LASreader_get_max_y(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_max_y();
}
F64 LASreader_get_max_z(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_max_z();
}
F64 LASreader_get_x(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_x();
}
F64 LASreader_get_y(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_y();
}
F64 LASreader_get_z(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_z();
}
F64 LASreader_get_x_1(WLASreader* self, const I32 x){
    return reinterpret_cast<LASreader*>(self)->get_x(x);
}
F64 LASreader_get_y_1(WLASreader* self, const I32 y){
    return reinterpret_cast<LASreader*>(self)->get_y(y);
}
F64 LASreader_get_z_1(WLASreader* self, const I32 z){
    return reinterpret_cast<LASreader*>(self)->get_z(z);
}
I64 LASreader_get_X(WLASreader* self, const F64 x){
    return reinterpret_cast<LASreader*>(self)->get_X(x);
}
I64 LASreader_get_Y(WLASreader* self, const F64 y){
    return reinterpret_cast<LASreader*>(self)->get_Y(y);
}
I64 LASreader_get_Z(WLASreader* self, const F64 z){
    return reinterpret_cast<LASreader*>(self)->get_Z(z);
}
ByteStreamIn* LASreader_get_stream(WLASreader* self){
    return reinterpret_cast<LASreader*>(self)->get_stream();
}
void LASreader_close(WLASreader* self, BOOL close_stream){
    reinterpret_cast<LASreader*>(self)->close(close_stream);
}
void LASreader_destroy(WLASreader* self){
     delete reinterpret_cast<LASreader*>(self);
}
void LASreader_dealloc(WLASreader* self){
    reinterpret_cast<LASreader*>(self)->dealloc();
}
BOOL LASwaveform13reader_open(WLASwaveform13reader* self, const char * file_name, I64 start_of_waveform_data_packet_record, const class LASvlr_wave_packet_descr *const * wave_packet_descr){
    return reinterpret_cast<LASwaveform13reader*>(self)->open(file_name, start_of_waveform_data_packet_record, wave_packet_descr);
}
BOOL LASwaveform13reader_is_compressed(WLASwaveform13reader* self){
    return reinterpret_cast<LASwaveform13reader*>(self)->is_compressed();
}
BOOL LASwaveform13reader_read_waveform(WLASwaveform13reader* self, WLASpoint* point){
    return reinterpret_cast<LASwaveform13reader*>(self)->read_waveform(reinterpret_cast<LASpoint*>(point));
}
BOOL LASwaveform13reader_get_samples(WLASwaveform13reader* self){
    return reinterpret_cast<LASwaveform13reader*>(self)->get_samples();
}
BOOL LASwaveform13reader_has_samples(WLASwaveform13reader* self){
    return reinterpret_cast<LASwaveform13reader*>(self)->has_samples();
}
BOOL LASwaveform13reader_get_samples_xyz(WLASwaveform13reader* self){
    return reinterpret_cast<LASwaveform13reader*>(self)->get_samples_xyz();
}
BOOL LASwaveform13reader_has_samples_xyz(WLASwaveform13reader* self){
    return reinterpret_cast<LASwaveform13reader*>(self)->has_samples_xyz();
}
void LASwaveform13reader_close(WLASwaveform13reader* self){
    reinterpret_cast<LASwaveform13reader*>(self)->close();
}
WLASwaveform13reader* LASwaveform13reader_create(){
    return reinterpret_cast<WLASwaveform13reader*>( new LASwaveform13reader());
}
void LASwaveform13reader_destroy(WLASwaveform13reader* self){
     delete reinterpret_cast<LASwaveform13reader*>(self);
}
void LASreadOpener_set_io_ibuffer_size(WLASreadOpener* self, const U32 buffer_size){
    reinterpret_cast<LASreadOpener*>(self)->set_io_ibuffer_size(buffer_size);
}
U32 LASreadOpener_get_io_ibuffer_size(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_io_ibuffer_size();
}
U32 LASreadOpener_get_file_name_number(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_file_name_number();
}
U32 LASreadOpener_get_file_name_current(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_file_name_current();
}
const CHAR * LASreadOpener_get_file_name(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_file_name();
}
const CHAR * LASreadOpener_get_file_name_only(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_file_name_only();
}
const CHAR * LASreadOpener_get_file_extension_only(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_file_extension_only();
}
const CHAR * LASreadOpener_get_file_name_1(WLASreadOpener* self, U32 number){
    return reinterpret_cast<LASreadOpener*>(self)->get_file_name(number);
}
const CHAR * LASreadOpener_get_file_name_only_1(WLASreadOpener* self, U32 number){
    return reinterpret_cast<LASreadOpener*>(self)->get_file_name_only(number);
}
const CHAR * LASreadOpener_get_file_extension_only_1(WLASreadOpener* self, U32 number){
    return reinterpret_cast<LASreadOpener*>(self)->get_file_extension_only(number);
}
CHAR * LASreadOpener_get_file_name_base(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_file_name_base();
}
CHAR * LASreadOpener_get_file_name_base_1(WLASreadOpener* self, U32 number){
    return reinterpret_cast<LASreadOpener*>(self)->get_file_name_base(number);
}
void LASreadOpener_set_file_name(WLASreadOpener* self, const CHAR * file_name, BOOL unique){
    reinterpret_cast<LASreadOpener*>(self)->set_file_name(file_name, unique);
}
BOOL LASreadOpener_add_file_name(WLASreadOpener* self, const CHAR * file_name, BOOL unique){
    return reinterpret_cast<LASreadOpener*>(self)->add_file_name(file_name, unique);
}
BOOL LASreadOpener_add_list_of_files(WLASreadOpener* self, const CHAR * list_of_files, BOOL unique){
    return reinterpret_cast<LASreadOpener*>(self)->add_list_of_files(list_of_files, unique);
}
void LASreadOpener_delete_file_name(WLASreadOpener* self, U32 file_name_id){
    reinterpret_cast<LASreadOpener*>(self)->delete_file_name(file_name_id);
}
BOOL LASreadOpener_set_file_name_current(WLASreadOpener* self, U32 file_name_id){
    return reinterpret_cast<LASreadOpener*>(self)->set_file_name_current(file_name_id);
}
I32 LASreadOpener_get_file_format(WLASreadOpener* self, U32 number){
    return reinterpret_cast<LASreadOpener*>(self)->get_file_format(number);
}
void LASreadOpener_set_merged(WLASreadOpener* self, const BOOL merged){
    reinterpret_cast<LASreadOpener*>(self)->set_merged(merged);
}
BOOL LASreadOpener_is_merged(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->is_merged();
}
void LASreadOpener_set_stored(WLASreadOpener* self, const BOOL stored){
    reinterpret_cast<LASreadOpener*>(self)->set_stored(stored);
}
BOOL LASreadOpener_is_stored(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->is_stored();
}
void LASreadOpener_set_buffer_size(WLASreadOpener* self, const F32 buffer_size){
    reinterpret_cast<LASreadOpener*>(self)->set_buffer_size(buffer_size);
}
F32 LASreadOpener_get_buffer_size(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_buffer_size();
}
void LASreadOpener_set_neighbor_file_name(WLASreadOpener* self, const CHAR * neighbor_file_name, BOOL unique){
    reinterpret_cast<LASreadOpener*>(self)->set_neighbor_file_name(neighbor_file_name, unique);
}
BOOL LASreadOpener_add_neighbor_file_name(WLASreadOpener* self, const CHAR * neighbor_file_name, BOOL unique){
    return reinterpret_cast<LASreadOpener*>(self)->add_neighbor_file_name(neighbor_file_name, unique);
}
BOOL LASreadOpener_add_neighbor_file_name_1(WLASreadOpener* self, const CHAR * file_name, I64 npoints, F64 min_x, F64 min_y, F64 max_x, F64 max_y, BOOL unique){
    return reinterpret_cast<LASreadOpener*>(self)->add_neighbor_file_name(file_name, npoints, min_x, min_y, max_x, max_y, unique);
}
BOOL LASreadOpener_add_neighbor_list_of_files(WLASreadOpener* self, const CHAR * list_of_files, BOOL unique){
    return reinterpret_cast<LASreadOpener*>(self)->add_neighbor_list_of_files(list_of_files, unique);
}
void LASreadOpener_set_auto_reoffset(WLASreadOpener* self, const BOOL auto_reoffset){
    reinterpret_cast<LASreadOpener*>(self)->set_auto_reoffset(auto_reoffset);
}
BOOL LASreadOpener_is_auto_reoffset(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->is_auto_reoffset();
}
void LASreadOpener_set_files_are_flightlines(WLASreadOpener* self, const I32 files_are_flightlines){
    reinterpret_cast<LASreadOpener*>(self)->set_files_are_flightlines(files_are_flightlines);
}
I32 LASreadOpener_are_files_flightlines(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->are_files_flightlines();
}
void LASreadOpener_set_files_are_flightlines_index(WLASreadOpener* self, const I32 files_are_flightlines_index){
    reinterpret_cast<LASreadOpener*>(self)->set_files_are_flightlines_index(files_are_flightlines_index);
}
I32 LASreadOpener_get_files_flight_index(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_files_flight_index();
}
void LASreadOpener_set_apply_file_source_ID(WLASreadOpener* self, const BOOL apply_file_source_ID){
    reinterpret_cast<LASreadOpener*>(self)->set_apply_file_source_ID(apply_file_source_ID);
}
BOOL LASreadOpener_applying_file_source_ID(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->applying_file_source_ID();
}
void LASreadOpener_set_scale_factor(WLASreadOpener* self, const F64 * scale_factor){
    reinterpret_cast<LASreadOpener*>(self)->set_scale_factor(scale_factor);
}
const F64 * LASreadOpener_get_scale_factor(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_scale_factor();
}
void LASreadOpener_set_offset(WLASreadOpener* self, const F64 * offset){
    reinterpret_cast<LASreadOpener*>(self)->set_offset(offset);
}
const F64 * LASreadOpener_get_offset(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_offset();
}
void LASreadOpener_set_translate_intensity(WLASreadOpener* self, const F32 translation){
    reinterpret_cast<LASreadOpener*>(self)->set_translate_intensity(translation);
}
void LASreadOpener_set_scale_intensity(WLASreadOpener* self, const F32 scale){
    reinterpret_cast<LASreadOpener*>(self)->set_scale_intensity(scale);
}
void LASreadOpener_set_translate_scan_angle(WLASreadOpener* self, const F32 translate_scan_angle){
    reinterpret_cast<LASreadOpener*>(self)->set_translate_scan_angle(translate_scan_angle);
}
void LASreadOpener_set_scale_scan_angle(WLASreadOpener* self, const F32 scale_scan_angle){
    reinterpret_cast<LASreadOpener*>(self)->set_scale_scan_angle(scale_scan_angle);
}
void LASreadOpener_add_attribute(WLASreadOpener* self, I32 data_type, const CHAR * name, const CHAR * description, F64 scale, F64 offset, F64 pre_scale, F64 pre_offset, F64 no_data){
    reinterpret_cast<LASreadOpener*>(self)->add_attribute(data_type, name, description, scale, offset, pre_scale, pre_offset, no_data);
}
BOOL LASreadOpener_set_point_type(WLASreadOpener* self, U8 point_type){
    return reinterpret_cast<LASreadOpener*>(self)->set_point_type(point_type);
}
void LASreadOpener_set_parse_string(WLASreadOpener* self, const CHAR * parse_string){
    reinterpret_cast<LASreadOpener*>(self)->set_parse_string(parse_string);
}
void LASreadOpener_set_skip_lines(WLASreadOpener* self, const U32 number_of_lines){
    reinterpret_cast<LASreadOpener*>(self)->set_skip_lines(number_of_lines);
}
void LASreadOpener_set_populate_header(WLASreadOpener* self, BOOL populate_header){
    reinterpret_cast<LASreadOpener*>(self)->set_populate_header(populate_header);
}
void LASreadOpener_set_keep_lastiling(WLASreadOpener* self, BOOL keep_lastiling){
    reinterpret_cast<LASreadOpener*>(self)->set_keep_lastiling(keep_lastiling);
}
void LASreadOpener_set_pipe_on(WLASreadOpener* self, BOOL pipe_on){
    reinterpret_cast<LASreadOpener*>(self)->set_pipe_on(pipe_on);
}
const CHAR * LASreadOpener_get_parse_string(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_parse_string();
}
void LASreadOpener_usage(WLASreadOpener* self){
    reinterpret_cast<LASreadOpener*>(self)->usage();
}
void LASreadOpener_set_decompress_selective(WLASreadOpener* self, U32 decompress_selective){
    reinterpret_cast<LASreadOpener*>(self)->set_decompress_selective(decompress_selective);
}
void LASreadOpener_set_inside_tile(WLASreadOpener* self, const F32 ll_x, const F32 ll_y, const F32 size){
    reinterpret_cast<LASreadOpener*>(self)->set_inside_tile(ll_x, ll_y, size);
}
void LASreadOpener_set_inside_circle(WLASreadOpener* self, const F64 center_x, const F64 center_y, const F64 radius){
    reinterpret_cast<LASreadOpener*>(self)->set_inside_circle(center_x, center_y, radius);
}
void LASreadOpener_set_inside_rectangle(WLASreadOpener* self, const F64 min_x, const F64 min_y, const F64 max_x, const F64 max_y){
    reinterpret_cast<LASreadOpener*>(self)->set_inside_rectangle(min_x, min_y, max_x, max_y);
}
BOOL LASreadOpener_parse(WLASreadOpener* self, int argc, char ** argv, BOOL parse_ignore){
    return reinterpret_cast<LASreadOpener*>(self)->parse(argc, argv, parse_ignore);
}
BOOL LASreadOpener_is_piped(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->is_piped();
}
BOOL LASreadOpener_is_buffered(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->is_buffered();
}
BOOL LASreadOpener_is_header_populated(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->is_header_populated();
}
BOOL LASreadOpener_active(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->active();
}
BOOL LASreadOpener_is_inside(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->is_inside();
}
I32 LASreadOpener_unparse(WLASreadOpener* self, CHAR * string){
    return reinterpret_cast<LASreadOpener*>(self)->unparse(string);
}
void LASreadOpener_set_filter(WLASreadOpener* self, WLASfilter* filter){
    reinterpret_cast<LASreadOpener*>(self)->set_filter(reinterpret_cast<LASfilter*>(filter));
}
WLASfilter* LASreadOpener_get_filter(WLASreadOpener* self){
    return reinterpret_cast<WLASfilter*>(reinterpret_cast<LASreadOpener*>(self)->get_filter());
}
void LASreadOpener_set_transform(WLASreadOpener* self, WLAStransform* transform){
    reinterpret_cast<LASreadOpener*>(self)->set_transform(reinterpret_cast<LAStransform*>(transform));
}
WLAStransform* LASreadOpener_get_transform(WLASreadOpener* self){
    return reinterpret_cast<WLAStransform*>(reinterpret_cast<LASreadOpener*>(self)->get_transform());
}
void LASreadOpener_set_ignore(WLASreadOpener* self, WLASignore* ignore){
    reinterpret_cast<LASreadOpener*>(self)->set_ignore(reinterpret_cast<LASignore*>(ignore));
}
WLASignore* LASreadOpener_get_ignore(WLASreadOpener* self){
    return reinterpret_cast<WLASignore*>(reinterpret_cast<LASreadOpener*>(self)->get_ignore());
}
void LASreadOpener_reset(WLASreadOpener* self){
    reinterpret_cast<LASreadOpener*>(self)->reset();
}
const CHAR * LASreadOpener_get_temp_file_base(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_temp_file_base();
}
WLASreader* LASreadOpener_open(WLASreadOpener* self, const CHAR * other_file_name, BOOL reset_after_other){
    return reinterpret_cast<WLASreader*>(reinterpret_cast<LASreadOpener*>(self)->open(other_file_name, reset_after_other));
}
BOOL LASreadOpener_reopen(WLASreadOpener* self, WLASreader* lasreader, BOOL remain_buffered){
    return reinterpret_cast<LASreadOpener*>(self)->reopen(reinterpret_cast<LASreader*>(lasreader), remain_buffered);
}
WLASwaveform13reader* LASreadOpener_open_waveform13(WLASreadOpener* self, WLASheader* lasheader){
    return reinterpret_cast<WLASwaveform13reader*>(reinterpret_cast<LASreadOpener*>(self)->open_waveform13(reinterpret_cast<LASheader*>(lasheader)));
}
I32 LASreadOpener_get_number_attributes(WLASreadOpener* self){
    return reinterpret_cast<LASreadOpener*>(self)->get_number_attributes();
}
I32 LASreadOpener_get_attribute_data_type(WLASreadOpener* self, U32 index){
    return reinterpret_cast<LASreadOpener*>(self)->get_attribute_data_type(index);
}
const CHAR * LASreadOpener_get_attribute_name(WLASreadOpener* self, U32 index){
    return reinterpret_cast<LASreadOpener*>(self)->get_attribute_name(index);
}
const CHAR * LASreadOpener_get_attribute_description(WLASreadOpener* self, U32 index){
    return reinterpret_cast<LASreadOpener*>(self)->get_attribute_description(index);
}
F64 LASreadOpener_get_attribute_scale(WLASreadOpener* self, U32 index){
    return reinterpret_cast<LASreadOpener*>(self)->get_attribute_scale(index);
}
F64 LASreadOpener_get_attribute_offset(WLASreadOpener* self, U32 index){
    return reinterpret_cast<LASreadOpener*>(self)->get_attribute_offset(index);
}
F64 LASreadOpener_get_attribute_no_data(WLASreadOpener* self, U32 index){
    return reinterpret_cast<LASreadOpener*>(self)->get_attribute_no_data(index);
}
WLASreadOpener* LASreadOpener_create(){
    return reinterpret_cast<WLASreadOpener*>( new LASreadOpener());
}
void LASreadOpener_destroy(WLASreadOpener* self){
     delete reinterpret_cast<LASreadOpener*>(self);
}
void LASreaderLAS_set_delete_stream(WLASreaderLAS* self, BOOL delete_stream){
    reinterpret_cast<LASreaderLAS*>(self)->set_delete_stream(delete_stream);
}
BOOL LASreaderLAS_open(WLASreaderLAS* self, const char * file_name, I32 io_buffer_size, BOOL peek_only, U32 decompress_selective){
    return reinterpret_cast<LASreaderLAS*>(self)->open(file_name, io_buffer_size, peek_only, decompress_selective);
}
BOOL LASreaderLAS_open_1(WLASreaderLAS* self, _IO_FILE* file, BOOL peek_only, U32 decompress_selective){
    return reinterpret_cast<LASreaderLAS*>(self)->open(file, peek_only, decompress_selective);
}
BOOL LASreaderLAS_open_3(WLASreaderLAS* self, ByteStreamIn* stream, BOOL peek_only, U32 decompress_selective){
    return reinterpret_cast<LASreaderLAS*>(self)->open(stream, peek_only, decompress_selective);
}
I32 LASreaderLAS_get_format(WLASreaderLAS* self){
    return reinterpret_cast<LASreaderLAS*>(self)->get_format();
}
BOOL LASreaderLAS_seek(WLASreaderLAS* self, const I64 p_index){
    return reinterpret_cast<LASreaderLAS*>(self)->seek(p_index);
}
ByteStreamIn* LASreaderLAS_get_stream(WLASreaderLAS* self){
    return reinterpret_cast<LASreaderLAS*>(self)->get_stream();
}
void LASreaderLAS_close(WLASreaderLAS* self, BOOL close_stream){
    reinterpret_cast<LASreaderLAS*>(self)->close(close_stream);
}
WLASreaderLAS* LASreaderLAS_create(){
    return reinterpret_cast<WLASreaderLAS*>( new LASreaderLAS());
}
void LASreaderLAS_destroy(WLASreaderLAS* self){
     delete reinterpret_cast<LASreaderLAS*>(self);
}
WLASreaderLASrescale* LASreaderLASrescale_create(F64 x_scale_factor, F64 y_scale_factor, F64 z_scale_factor, BOOL check_for_overflow){
    return reinterpret_cast<WLASreaderLASrescale*>( new LASreaderLASrescale(x_scale_factor, y_scale_factor, z_scale_factor, check_for_overflow));
}
WLASreaderLASreoffset* LASreaderLASreoffset_create(F64 x_offset, F64 y_offset, F64 z_offset){
    return reinterpret_cast<WLASreaderLASreoffset*>( new LASreaderLASreoffset(x_offset, y_offset, z_offset));
}
WLASreaderLASreoffset* LASreaderLASreoffset_create_1(){
    return reinterpret_cast<WLASreaderLASreoffset*>( new LASreaderLASreoffset());
}
WLASreaderLASrescalereoffset* LASreaderLASrescalereoffset_create(F64 x_scale_factor, F64 y_scale_factor, F64 z_scale_factor, F64 x_offset, F64 y_offset, F64 z_offset){
    return reinterpret_cast<WLASreaderLASrescalereoffset*>( new LASreaderLASrescalereoffset(x_scale_factor, y_scale_factor, z_scale_factor, x_offset, y_offset, z_offset));
}
WLASreaderLASrescalereoffset* LASreaderLASrescalereoffset_create_1(F64 x_scale_factor, F64 y_scale_factor, F64 z_scale_factor){
    return reinterpret_cast<WLASreaderLASrescalereoffset*>( new LASreaderLASrescalereoffset(x_scale_factor, y_scale_factor, z_scale_factor));
}
#ifdef __cplusplus
}
#endif
