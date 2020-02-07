#ifndef __CWRAPPER_H
#define __CWRAPPER_H_

#include <stdbool.h>

typedef char CHAR;

typedef int I32;
typedef short I16;
typedef char I8;

typedef unsigned int U32;
typedef unsigned short U16;
typedef unsigned char U8;

#if defined(_WIN32) && !defined(__MINGW32__) // 64 byte integer under Windows
typedef unsigned __int64 U64;
typedef __int64 I64;
#else // 64 byte integer elsewhere ...
typedef unsigned long long U64;
typedef long long I64;
#endif

typedef float F32;
typedef double F64;

#if defined(_MSC_VER) || defined(__MINGW32__)
typedef int BOOL;
#else
typedef bool BOOL;
#endif
#ifdef __cplusplus
extern "C"{
#endif

struct      WLASvlr_lastiling;
typedef     struct WLASvlr_lastiling WLASvlr_lastiling;
// LASvlr_lastiling_create
WLASvlr_lastiling* LASvlr_lastiling_create();
struct      WLASvlr_lasoriginal;
typedef     struct WLASvlr_lasoriginal WLASvlr_lasoriginal;
// LASvlr_lasoriginal_create
WLASvlr_lasoriginal* LASvlr_lasoriginal_create();
struct      WLASitem;
typedef     struct WLASitem WLASitem;

// Method const char * _get_name
// LASitem_get_name
const char * LASitem_get_name(WLASitem* self);
struct      WLASzip;
typedef     struct WLASzip WLASzip;
// Method _Bool _check_compressor
// LASzip_check_compressor
// arg 0: const unsigned short compressor
_Bool LASzip_check_compressor(WLASzip* self, const unsigned short compressor);
// Method _Bool _check_coder
// LASzip_check_coder
// arg 0: const unsigned short coder
_Bool LASzip_check_coder(WLASzip* self, const unsigned short coder);
// Method _Bool _check_item
// LASzip_check_item
// arg 0: const class LASitem * item
_Bool LASzip_check_item(WLASzip* self, WLASitem* item);
// Method _Bool _check_items
// LASzip_check_items
// arg 0: const unsigned short num_items
// arg 1: const class LASitem * items
// arg 2: const unsigned short point_size
_Bool LASzip_check_items(WLASzip* self, const unsigned short num_items, WLASitem* items, const unsigned short point_size);
// Method _Bool _check
// LASzip_check
// arg 0: const unsigned short point_size
_Bool LASzip_check(WLASzip* self, const unsigned short point_size);
// Method _Bool _is_standard
// LASzip_is_standard
// arg 0: const unsigned short num_items
// arg 1: const class LASitem * items
// arg 2: unsigned char * point_type
// arg 3: unsigned short * record_length
_Bool LASzip_is_standard(WLASzip* self, const unsigned short num_items, WLASitem* items, unsigned char * point_type, unsigned short * record_length);
// Method _Bool _is_standard
// LASzip_is_standard
// arg 0: unsigned char * point_type
// arg 1: unsigned short * record_length
_Bool LASzip_is_standard_1(WLASzip* self, unsigned char * point_type, unsigned short * record_length);
// Method _Bool _unpack
// LASzip_unpack
// arg 0: const unsigned char * bytes
// arg 1: const int num
_Bool LASzip_unpack(WLASzip* self, const unsigned char * bytes, const int num);
// Method _Bool _pack
// LASzip_pack
// arg 0: unsigned char *& bytes
// arg 1: int & num
_Bool LASzip_pack(WLASzip* self, unsigned char *& bytes, int & num);
// Method _Bool _request_compatibility_mode
// LASzip_request_compatibility_mode
// arg 0: const unsigned short requested_compatibility_mode
_Bool LASzip_request_compatibility_mode(WLASzip* self, const unsigned short requested_compatibility_mode);
// Method _Bool _setup
// LASzip_setup
// arg 0: const unsigned char point_type
// arg 1: const unsigned short point_size
// arg 2: const unsigned short compressor
_Bool LASzip_setup_1(WLASzip* self, const unsigned char point_type, const unsigned short point_size, const unsigned short compressor);
// Method _Bool _setup
// LASzip_setup
// arg 0: const unsigned short num_items
// arg 1: const class LASitem * items
// arg 2: const unsigned short compressor
_Bool LASzip_setup_2(WLASzip* self, const unsigned short num_items, WLASitem* items, const unsigned short compressor);
// Method _Bool _set_chunk_size
// LASzip_set_chunk_size
// arg 0: const unsigned int chunk_size
_Bool LASzip_set_chunk_size(WLASzip* self, const unsigned int chunk_size);
// Method _Bool _request_version
// LASzip_request_version
// arg 0: const unsigned short requested_version
_Bool LASzip_request_version(WLASzip* self, const unsigned short requested_version);
// Method const char * _get_error
// LASzip_get_error
const char * LASzip_get_error(WLASzip* self);
// LASzip_create
WLASzip* LASzip_create();
// LASzip_destroy
void LASzip_destroy(WLASzip* self);
struct      WLASquantizer;
typedef     struct WLASquantizer WLASquantizer;
// Method F64 _get_x
// LASquantizer_get_x
// arg 0: const I32 X
F64 LASquantizer_get_x(WLASquantizer* self, const I32 X);
// Method F64 _get_y
// LASquantizer_get_y
// arg 0: const I32 Y
F64 LASquantizer_get_y(WLASquantizer* self, const I32 Y);
// Method F64 _get_z
// LASquantizer_get_z
// arg 0: const I32 Z
F64 LASquantizer_get_z(WLASquantizer* self, const I32 Z);
// Method I64 _get_X
// LASquantizer_get_X
// arg 0: const F64 x
I64 LASquantizer_get_X(WLASquantizer* self, const F64 x);
// Method I64 _get_Y
// LASquantizer_get_Y
// arg 0: const F64 y
I64 LASquantizer_get_Y(WLASquantizer* self, const F64 y);
// Method I64 _get_Z
// LASquantizer_get_Z
// arg 0: const F64 z
I64 LASquantizer_get_Z(WLASquantizer* self, const F64 z);
// LASquantizer_create
WLASquantizer* LASquantizer_create();
struct      WLASattribute;
typedef     struct WLASattribute WLASattribute;
// LASattribute_create
// arg 0: U8 size
WLASattribute* LASattribute_create(U8 size);
// LASattribute_create
// arg 0: U32 type
// arg 1: const CHAR * name
// arg 2: const CHAR * description
WLASattribute* LASattribute_create_1(U32 type, const CHAR * name, const CHAR * description);
// Method BOOL _set_no_data
// LASattribute_set_no_data
// arg 0: U8 no_data
BOOL LASattribute_set_no_data(WLASattribute* self, U8 no_data);
// Method BOOL _set_no_data
// LASattribute_set_no_data
// arg 0: I8 no_data
BOOL LASattribute_set_no_data_1(WLASattribute* self, I8 no_data);
// Method BOOL _set_no_data
// LASattribute_set_no_data
// arg 0: U16 no_data
BOOL LASattribute_set_no_data_2(WLASattribute* self, U16 no_data);
// Method BOOL _set_no_data
// LASattribute_set_no_data
// arg 0: I16 no_data
BOOL LASattribute_set_no_data_3(WLASattribute* self, I16 no_data);
// Method BOOL _set_no_data
// LASattribute_set_no_data
// arg 0: U32 no_data
BOOL LASattribute_set_no_data_4(WLASattribute* self, U32 no_data);
// Method BOOL _set_no_data
// LASattribute_set_no_data
// arg 0: I32 no_data
BOOL LASattribute_set_no_data_5(WLASattribute* self, I32 no_data);
// Method BOOL _set_no_data
// LASattribute_set_no_data
// arg 0: U64 no_data
BOOL LASattribute_set_no_data_6(WLASattribute* self, U64 no_data);
// Method BOOL _set_no_data
// LASattribute_set_no_data
// arg 0: I64 no_data
BOOL LASattribute_set_no_data_7(WLASattribute* self, I64 no_data);
// Method BOOL _set_no_data
// LASattribute_set_no_data
// arg 0: F32 no_data
BOOL LASattribute_set_no_data_8(WLASattribute* self, F32 no_data);
// Method BOOL _set_no_data
// LASattribute_set_no_data
// arg 0: F64 no_data
BOOL LASattribute_set_no_data_9(WLASattribute* self, F64 no_data);
// Method void _set_min
// LASattribute_set_min
// arg 0: U8 * min
void LASattribute_set_min(WLASattribute* self, U8 * min);
// Method void _update_min
// LASattribute_update_min
// arg 0: U8 * min
void LASattribute_update_min(WLASattribute* self, U8 * min);
// Method BOOL _set_min
// LASattribute_set_min
// arg 0: U8 min
BOOL LASattribute_set_min_1(WLASattribute* self, U8 min);
// Method BOOL _set_min
// LASattribute_set_min
// arg 0: I8 min
BOOL LASattribute_set_min_2(WLASattribute* self, I8 min);
// Method BOOL _set_min
// LASattribute_set_min
// arg 0: U16 min
BOOL LASattribute_set_min_3(WLASattribute* self, U16 min);
// Method BOOL _set_min
// LASattribute_set_min
// arg 0: I16 min
BOOL LASattribute_set_min_4(WLASattribute* self, I16 min);
// Method BOOL _set_min
// LASattribute_set_min
// arg 0: U32 min
BOOL LASattribute_set_min_5(WLASattribute* self, U32 min);
// Method BOOL _set_min
// LASattribute_set_min
// arg 0: I32 min
BOOL LASattribute_set_min_6(WLASattribute* self, I32 min);
// Method BOOL _set_min
// LASattribute_set_min
// arg 0: U64 min
BOOL LASattribute_set_min_7(WLASattribute* self, U64 min);
// Method BOOL _set_min
// LASattribute_set_min
// arg 0: I64 min
BOOL LASattribute_set_min_8(WLASattribute* self, I64 min);
// Method BOOL _set_min
// LASattribute_set_min
// arg 0: F32 min
BOOL LASattribute_set_min_9(WLASattribute* self, F32 min);
// Method BOOL _set_min
// LASattribute_set_min
// arg 0: F64 min
BOOL LASattribute_set_min_10(WLASattribute* self, F64 min);
// Method void _set_max
// LASattribute_set_max
// arg 0: U8 * max
void LASattribute_set_max(WLASattribute* self, U8 * max);
// Method void _update_max
// LASattribute_update_max
// arg 0: U8 * max
void LASattribute_update_max(WLASattribute* self, U8 * max);
// Method BOOL _set_max
// LASattribute_set_max
// arg 0: U8 max
BOOL LASattribute_set_max_1(WLASattribute* self, U8 max);
// Method BOOL _set_max
// LASattribute_set_max
// arg 0: I8 max
BOOL LASattribute_set_max_2(WLASattribute* self, I8 max);
// Method BOOL _set_max
// LASattribute_set_max
// arg 0: U16 max
BOOL LASattribute_set_max_3(WLASattribute* self, U16 max);
// Method BOOL _set_max
// LASattribute_set_max
// arg 0: I16 max
BOOL LASattribute_set_max_4(WLASattribute* self, I16 max);
// Method BOOL _set_max
// LASattribute_set_max
// arg 0: U32 max
BOOL LASattribute_set_max_5(WLASattribute* self, U32 max);
// Method BOOL _set_max
// LASattribute_set_max
// arg 0: I32 max
BOOL LASattribute_set_max_6(WLASattribute* self, I32 max);
// Method BOOL _set_max
// LASattribute_set_max
// arg 0: U64 max
BOOL LASattribute_set_max_7(WLASattribute* self, U64 max);
// Method BOOL _set_max
// LASattribute_set_max
// arg 0: I64 max
BOOL LASattribute_set_max_8(WLASattribute* self, I64 max);
// Method BOOL _set_max
// LASattribute_set_max
// arg 0: F32 max
BOOL LASattribute_set_max_9(WLASattribute* self, F32 max);
// Method BOOL _set_max
// LASattribute_set_max
// arg 0: F64 max
BOOL LASattribute_set_max_10(WLASattribute* self, F64 max);
// Method BOOL _set_scale
// LASattribute_set_scale
// arg 0: F64 scale
BOOL LASattribute_set_scale(WLASattribute* self, F64 scale);
// Method BOOL _set_offset
// LASattribute_set_offset
// arg 0: F64 offset
BOOL LASattribute_set_offset(WLASattribute* self, F64 offset);
// Method BOOL _unset_scale
// LASattribute_unset_scale
BOOL LASattribute_unset_scale(WLASattribute* self);
// Method BOOL _unset_offset
// LASattribute_unset_offset
BOOL LASattribute_unset_offset(WLASattribute* self);
// Method BOOL _has_no_data
// LASattribute_has_no_data
BOOL LASattribute_has_no_data(WLASattribute* self);
// Method BOOL _has_min
// LASattribute_has_min
BOOL LASattribute_has_min(WLASattribute* self);
// Method BOOL _has_max
// LASattribute_has_max
BOOL LASattribute_has_max(WLASattribute* self);
// Method BOOL _has_scale
// LASattribute_has_scale
BOOL LASattribute_has_scale(WLASattribute* self);
// Method BOOL _has_offset
// LASattribute_has_offset
BOOL LASattribute_has_offset(WLASattribute* self);
// Method U32 _get_size
// LASattribute_get_size
U32 LASattribute_get_size(WLASattribute* self);
// Method F64 _get_value_as_float
// LASattribute_get_value_as_float
// arg 0: U8 * pointer
F64 LASattribute_get_value_as_float(WLASattribute* self, U8 * pointer);
// Method void _set_value_as_float
// LASattribute_set_value_as_float
// arg 0: U8 * pointer
// arg 1: F64 value
void LASattribute_set_value_as_float(WLASattribute* self, U8 * pointer, F64 value);
struct      WLASattributer;
typedef     struct WLASattributer WLASattributer;
// LASattributer_create
WLASattributer* LASattributer_create();
// LASattributer_destroy
void LASattributer_destroy(WLASattributer* self);
// Method void _clean_attributes
// LASattributer_clean_attributes
void LASattributer_clean_attributes(WLASattributer* self);
// Method BOOL _init_attributes
// LASattributer_init_attributes
// arg 0: U32 number_attributes
// arg 1: class LASattribute * attributes
BOOL LASattributer_init_attributes(WLASattributer* self, U32 number_attributes, WLASattribute* attributes);
// Method I32 _add_attribute
// LASattributer_add_attribute
// arg 0: const class LASattribute attribute
I32 LASattributer_add_attribute(WLASattributer* self, WLASattribute* attribute);
// Method I16 _get_attributes_size
// LASattributer_get_attributes_size
I16 LASattributer_get_attributes_size(WLASattributer* self);
// Method I32 _get_attribute_index
// LASattributer_get_attribute_index
// arg 0: const CHAR * name
I32 LASattributer_get_attribute_index(WLASattributer* self, const CHAR * name);
// Method I32 _get_attribute_start
// LASattributer_get_attribute_start
// arg 0: const CHAR * name
I32 LASattributer_get_attribute_start(WLASattributer* self, const CHAR * name);
// Method I32 _get_attribute_start
// LASattributer_get_attribute_start
// arg 0: I32 index
I32 LASattributer_get_attribute_start_1(WLASattributer* self, I32 index);
// Method I32 _get_attribute_size
// LASattributer_get_attribute_size
// arg 0: I32 index
I32 LASattributer_get_attribute_size(WLASattributer* self, I32 index);
// Method const CHAR * _get_attribute_name
// LASattributer_get_attribute_name
// arg 0: I32 index
const CHAR * LASattributer_get_attribute_name(WLASattributer* self, I32 index);
// Method BOOL _remove_attribute
// LASattributer_remove_attribute
// arg 0: I32 index
BOOL LASattributer_remove_attribute(WLASattributer* self, I32 index);
// Method BOOL _remove_attribute
// LASattributer_remove_attribute
// arg 0: const CHAR * name
BOOL LASattributer_remove_attribute_1(WLASattributer* self, const CHAR * name);
struct      WLASwavepacket;
typedef     struct WLASwavepacket WLASwavepacket;
// LASwavepacket_create
WLASwavepacket* LASwavepacket_create();
// Method void _zero
// LASwavepacket_zero
void LASwavepacket_zero(WLASwavepacket* self);
// Method U8 _getIndex
// LASwavepacket_getIndex
U8 LASwavepacket_getIndex(WLASwavepacket* self);
// Method U64 _getOffset
// LASwavepacket_getOffset
U64 LASwavepacket_getOffset(WLASwavepacket* self);
// Method U32 _getSize
// LASwavepacket_getSize
U32 LASwavepacket_getSize(WLASwavepacket* self);
// Method F32 _getLocation
// LASwavepacket_getLocation
F32 LASwavepacket_getLocation(WLASwavepacket* self);
// Method F32 _getXt
// LASwavepacket_getXt
F32 LASwavepacket_getXt(WLASwavepacket* self);
// Method F32 _getYt
// LASwavepacket_getYt
F32 LASwavepacket_getYt(WLASwavepacket* self);
// Method F32 _getZt
// LASwavepacket_getZt
F32 LASwavepacket_getZt(WLASwavepacket* self);
// Method void _setIndex
// LASwavepacket_setIndex
// arg 0: U8 index
void LASwavepacket_setIndex(WLASwavepacket* self, U8 index);
// Method void _setOffset
// LASwavepacket_setOffset
// arg 0: U64 offset
void LASwavepacket_setOffset(WLASwavepacket* self, U64 offset);
// Method void _setSize
// LASwavepacket_setSize
// arg 0: U32 size
void LASwavepacket_setSize(WLASwavepacket* self, U32 size);
// Method void _setLocation
// LASwavepacket_setLocation
// arg 0: F32 location
void LASwavepacket_setLocation(WLASwavepacket* self, F32 location);
// Method void _setXt
// LASwavepacket_setXt
// arg 0: F32 xt
void LASwavepacket_setXt(WLASwavepacket* self, F32 xt);
// Method void _setYt
// LASwavepacket_setYt
// arg 0: F32 yt
void LASwavepacket_setYt(WLASwavepacket* self, F32 yt);
// Method void _setZt
// LASwavepacket_setZt
// arg 0: F32 zt
void LASwavepacket_setZt(WLASwavepacket* self, F32 zt);
// Method void _flipDirection
// LASwavepacket_flipDirection
void LASwavepacket_flipDirection(WLASwavepacket* self);
struct      WLASpoint;
typedef     struct WLASpoint WLASpoint;
// Method void _copy_to
// LASpoint_copy_to
// arg 0: U8 * buffer
void LASpoint_copy_to(WLASpoint* self, U8 * buffer);
// Method void _copy_from
// LASpoint_copy_from
// arg 0: const U8 * buffer
void LASpoint_copy_from(WLASpoint* self, const U8 * buffer);
// Method BOOL _init
// LASpoint_init
// arg 0: const class LASquantizer * quantizer
// arg 1: const U8 point_type
// arg 2: const U16 point_size
// arg 3: const class LASattributer * attributer
BOOL LASpoint_init(WLASpoint* self, WLASquantizer* quantizer, const U8 point_type, const U16 point_size, WLASattributer* attributer);
// Method BOOL _init
// LASpoint_init
// arg 0: const class LASquantizer * quantizer
// arg 1: const U32 num_items
// arg 2: const class LASitem * items
// arg 3: const class LASattributer * attributer
BOOL LASpoint_init_1(WLASpoint* self, WLASquantizer* quantizer, const U32 num_items, WLASitem* items, WLASattributer* attributer);
// Method BOOL _inside_rectangle
// LASpoint_inside_rectangle
// arg 0: const F64 r_min_x
// arg 1: const F64 r_min_y
// arg 2: const F64 r_max_x
// arg 3: const F64 r_max_y
BOOL LASpoint_inside_rectangle(WLASpoint* self, const F64 r_min_x, const F64 r_min_y, const F64 r_max_x, const F64 r_max_y);
// Method BOOL _inside_tile
// LASpoint_inside_tile
// arg 0: const F32 ll_x
// arg 1: const F32 ll_y
// arg 2: const F32 ur_x
// arg 3: const F32 ur_y
BOOL LASpoint_inside_tile(WLASpoint* self, const F32 ll_x, const F32 ll_y, const F32 ur_x, const F32 ur_y);
// Method BOOL _inside_circle
// LASpoint_inside_circle
// arg 0: const F64 center_x
// arg 1: const F64 center_y
// arg 2: F64 squared_radius
BOOL LASpoint_inside_circle(WLASpoint* self, const F64 center_x, const F64 center_y, F64 squared_radius);
// Method BOOL _inside_box
// LASpoint_inside_box
// arg 0: const F64 min_x
// arg 1: const F64 min_y
// arg 2: const F64 min_z
// arg 3: const F64 max_x
// arg 4: const F64 max_y
// arg 5: const F64 max_z
BOOL LASpoint_inside_box(WLASpoint* self, const F64 min_x, const F64 min_y, const F64 min_z, const F64 max_x, const F64 max_y, const F64 max_z);
// Method BOOL _inside_bounding_box
// LASpoint_inside_bounding_box
// arg 0: const F64 min_x
// arg 1: const F64 min_y
// arg 2: const F64 min_z
// arg 3: const F64 max_x
// arg 4: const F64 max_y
// arg 5: const F64 max_z
BOOL LASpoint_inside_bounding_box(WLASpoint* self, const F64 min_x, const F64 min_y, const F64 min_z, const F64 max_x, const F64 max_y, const F64 max_z);
// Method BOOL _is_zero
// LASpoint_is_zero
BOOL LASpoint_is_zero(WLASpoint* self);
// Method void _zero
// LASpoint_zero
void LASpoint_zero(WLASpoint* self);
// Method void _clean
// LASpoint_clean
void LASpoint_clean(WLASpoint* self);
// LASpoint_create
WLASpoint* LASpoint_create();
// Method BOOL _is_first
// LASpoint_is_first
BOOL LASpoint_is_first(WLASpoint* self);
// Method BOOL _is_intermediate
// LASpoint_is_intermediate
BOOL LASpoint_is_intermediate(WLASpoint* self);
// Method BOOL _is_last
// LASpoint_is_last
BOOL LASpoint_is_last(WLASpoint* self);
// Method BOOL _is_single
// LASpoint_is_single
BOOL LASpoint_is_single(WLASpoint* self);
// Method BOOL _is_first_of_many
// LASpoint_is_first_of_many
BOOL LASpoint_is_first_of_many(WLASpoint* self);
// Method BOOL _is_last_of_many
// LASpoint_is_last_of_many
BOOL LASpoint_is_last_of_many(WLASpoint* self);
// Method I32 _get_X
// LASpoint_get_X
I32 LASpoint_get_X(WLASpoint* self);
// Method I32 _get_Y
// LASpoint_get_Y
I32 LASpoint_get_Y(WLASpoint* self);
// Method I32 _get_Z
// LASpoint_get_Z
I32 LASpoint_get_Z(WLASpoint* self);
// Method U16 _get_intensity
// LASpoint_get_intensity
U16 LASpoint_get_intensity(WLASpoint* self);
// Method U8 _get_return_number
// LASpoint_get_return_number
U8 LASpoint_get_return_number(WLASpoint* self);
// Method U8 _get_number_of_returns
// LASpoint_get_number_of_returns
U8 LASpoint_get_number_of_returns(WLASpoint* self);
// Method U8 _get_scan_direction_flag
// LASpoint_get_scan_direction_flag
U8 LASpoint_get_scan_direction_flag(WLASpoint* self);
// Method U8 _get_edge_of_flight_line
// LASpoint_get_edge_of_flight_line
U8 LASpoint_get_edge_of_flight_line(WLASpoint* self);
// Method U8 _get_classification
// LASpoint_get_classification
U8 LASpoint_get_classification(WLASpoint* self);
// Method U8 _get_synthetic_flag
// LASpoint_get_synthetic_flag
U8 LASpoint_get_synthetic_flag(WLASpoint* self);
// Method U8 _get_keypoint_flag
// LASpoint_get_keypoint_flag
U8 LASpoint_get_keypoint_flag(WLASpoint* self);
// Method U8 _get_withheld_flag
// LASpoint_get_withheld_flag
U8 LASpoint_get_withheld_flag(WLASpoint* self);
// Method I8 _get_scan_angle_rank
// LASpoint_get_scan_angle_rank
I8 LASpoint_get_scan_angle_rank(WLASpoint* self);
// Method U8 _get_user_data
// LASpoint_get_user_data
U8 LASpoint_get_user_data(WLASpoint* self);
// Method U16 _get_point_source_ID
// LASpoint_get_point_source_ID
U16 LASpoint_get_point_source_ID(WLASpoint* self);
// Method U8 _get_deleted_flag
// LASpoint_get_deleted_flag
U8 LASpoint_get_deleted_flag(WLASpoint* self);
// Method F64 _get_gps_time
// LASpoint_get_gps_time
F64 LASpoint_get_gps_time(WLASpoint* self);
// Method const U16 * _get_RGB
// LASpoint_get_RGB
const U16 * LASpoint_get_RGB(WLASpoint* self);
// Method const U16 * _get_RGBI
// LASpoint_get_RGBI
const U16 * LASpoint_get_RGBI(WLASpoint* self);
// Method U16 _get_RGBI
// LASpoint_get_RGBI
// arg 0: const U32 band
U16 LASpoint_get_RGBI_1(WLASpoint* self, const U32 band);
// Method U16 _get_R
// LASpoint_get_R
U16 LASpoint_get_R(WLASpoint* self);
// Method U16 _get_G
// LASpoint_get_G
U16 LASpoint_get_G(WLASpoint* self);
// Method U16 _get_B
// LASpoint_get_B
U16 LASpoint_get_B(WLASpoint* self);
// Method U16 _get_I
// LASpoint_get_I
U16 LASpoint_get_I(WLASpoint* self);
// Method U16 _get_NIR
// LASpoint_get_NIR
U16 LASpoint_get_NIR(WLASpoint* self);
// Method void _set_X
// LASpoint_set_X
// arg 0: const I32 X
void LASpoint_set_X(WLASpoint* self, const I32 X);
// Method void _set_Y
// LASpoint_set_Y
// arg 0: const I32 Y
void LASpoint_set_Y(WLASpoint* self, const I32 Y);
// Method void _set_Z
// LASpoint_set_Z
// arg 0: const I32 Z
void LASpoint_set_Z(WLASpoint* self, const I32 Z);
// Method void _set_intensity
// LASpoint_set_intensity
// arg 0: const U16 intensity
void LASpoint_set_intensity(WLASpoint* self, const U16 intensity);
// Method void _set_return_number
// LASpoint_set_return_number
// arg 0: const U8 return_number
void LASpoint_set_return_number(WLASpoint* self, const U8 return_number);
// Method void _set_number_of_returns
// LASpoint_set_number_of_returns
// arg 0: const U8 number_of_returns
void LASpoint_set_number_of_returns(WLASpoint* self, const U8 number_of_returns);
// Method void _set_scan_direction_flag
// LASpoint_set_scan_direction_flag
// arg 0: const U8 scan_direction_flag
void LASpoint_set_scan_direction_flag(WLASpoint* self, const U8 scan_direction_flag);
// Method void _set_edge_of_flight_line
// LASpoint_set_edge_of_flight_line
// arg 0: const U8 edge_of_flight_line
void LASpoint_set_edge_of_flight_line(WLASpoint* self, const U8 edge_of_flight_line);
// Method void _set_classification
// LASpoint_set_classification
// arg 0: U8 classification
void LASpoint_set_classification(WLASpoint* self, U8 classification);
// Method void _set_synthetic_flag
// LASpoint_set_synthetic_flag
// arg 0: U8 synthetic_flag
void LASpoint_set_synthetic_flag(WLASpoint* self, U8 synthetic_flag);
// Method void _set_keypoint_flag
// LASpoint_set_keypoint_flag
// arg 0: U8 keypoint_flag
void LASpoint_set_keypoint_flag(WLASpoint* self, U8 keypoint_flag);
// Method void _set_withheld_flag
// LASpoint_set_withheld_flag
// arg 0: U8 withheld_flag
void LASpoint_set_withheld_flag(WLASpoint* self, U8 withheld_flag);
// Method void _set_scan_angle_rank
// LASpoint_set_scan_angle_rank
// arg 0: I8 scan_angle_rank
void LASpoint_set_scan_angle_rank(WLASpoint* self, I8 scan_angle_rank);
// Method void _set_user_data
// LASpoint_set_user_data
// arg 0: U8 user_data
void LASpoint_set_user_data(WLASpoint* self, U8 user_data);
// Method void _set_point_source_ID
// LASpoint_set_point_source_ID
// arg 0: U16 point_source_ID
void LASpoint_set_point_source_ID(WLASpoint* self, U16 point_source_ID);
// Method void _set_deleted_flag
// LASpoint_set_deleted_flag
// arg 0: U8 deleted_flag
void LASpoint_set_deleted_flag(WLASpoint* self, U8 deleted_flag);
// Method void _set_gps_time
// LASpoint_set_gps_time
// arg 0: const F64 gps_time
void LASpoint_set_gps_time(WLASpoint* self, const F64 gps_time);
// Method void _set_RGB
// LASpoint_set_RGB
// arg 0: const U16 * rgb
void LASpoint_set_RGB(WLASpoint* self, const U16 * rgb);
// Method void _set_RGBI
// LASpoint_set_RGBI
// arg 0: const U16 * rgb
void LASpoint_set_RGBI(WLASpoint* self, const U16 * rgb);
// Method void _set_RGBI
// LASpoint_set_RGBI
// arg 0: const U32 band
// arg 1: const U16 value
void LASpoint_set_RGBI_1(WLASpoint* self, const U32 band, const U16 value);
// Method void _set_R
// LASpoint_set_R
// arg 0: const U16 R
void LASpoint_set_R(WLASpoint* self, const U16 R);
// Method void _set_G
// LASpoint_set_G
// arg 0: const U16 G
void LASpoint_set_G(WLASpoint* self, const U16 G);
// Method void _set_B
// LASpoint_set_B
// arg 0: const U16 B
void LASpoint_set_B(WLASpoint* self, const U16 B);
// Method void _set_I
// LASpoint_set_I
// arg 0: const U16 I
void LASpoint_set_I(WLASpoint* self, const U16 I);
// Method void _set_NIR
// LASpoint_set_NIR
// arg 0: const U16 NIR
void LASpoint_set_NIR(WLASpoint* self, const U16 NIR);
// Method F64 _get_x
// LASpoint_get_x
F64 LASpoint_get_x(WLASpoint* self);
// Method F64 _get_y
// LASpoint_get_y
F64 LASpoint_get_y(WLASpoint* self);
// Method F64 _get_z
// LASpoint_get_z
F64 LASpoint_get_z(WLASpoint* self);
// Method BOOL _set_x
// LASpoint_set_x
// arg 0: const F64 x
BOOL LASpoint_set_x(WLASpoint* self, const F64 x);
// Method BOOL _set_y
// LASpoint_set_y
// arg 0: const F64 y
BOOL LASpoint_set_y(WLASpoint* self, const F64 y);
// Method BOOL _set_z
// LASpoint_set_z
// arg 0: const F64 z
BOOL LASpoint_set_z(WLASpoint* self, const F64 z);
// Method BOOL _is_extended_point_type
// LASpoint_is_extended_point_type
BOOL LASpoint_is_extended_point_type(WLASpoint* self);
// Method U8 _get_extended_classification
// LASpoint_get_extended_classification
U8 LASpoint_get_extended_classification(WLASpoint* self);
// Method U8 _get_extended_return_number
// LASpoint_get_extended_return_number
U8 LASpoint_get_extended_return_number(WLASpoint* self);
// Method U8 _get_extended_number_of_returns
// LASpoint_get_extended_number_of_returns
U8 LASpoint_get_extended_number_of_returns(WLASpoint* self);
// Method I16 _get_extended_scan_angle
// LASpoint_get_extended_scan_angle
I16 LASpoint_get_extended_scan_angle(WLASpoint* self);
// Method U8 _get_extended_overlap_flag
// LASpoint_get_extended_overlap_flag
U8 LASpoint_get_extended_overlap_flag(WLASpoint* self);
// Method U8 _get_extended_scanner_channel
// LASpoint_get_extended_scanner_channel
U8 LASpoint_get_extended_scanner_channel(WLASpoint* self);
// Method void _set_extended_classification
// LASpoint_set_extended_classification
// arg 0: U8 extended_classification
void LASpoint_set_extended_classification(WLASpoint* self, U8 extended_classification);
// Method void _set_extended_return_number
// LASpoint_set_extended_return_number
// arg 0: U8 extended_return_number
void LASpoint_set_extended_return_number(WLASpoint* self, U8 extended_return_number);
// Method void _set_extended_number_of_returns
// LASpoint_set_extended_number_of_returns
// arg 0: U8 extended_number_of_returns
void LASpoint_set_extended_number_of_returns(WLASpoint* self, U8 extended_number_of_returns);
// Method void _set_extended_scan_angle
// LASpoint_set_extended_scan_angle
// arg 0: I16 extended_scan_angle
void LASpoint_set_extended_scan_angle(WLASpoint* self, I16 extended_scan_angle);
// Method void _set_extended_overlap_flag
// LASpoint_set_extended_overlap_flag
// arg 0: U8 extended_overlap_flag
void LASpoint_set_extended_overlap_flag(WLASpoint* self, U8 extended_overlap_flag);
// Method void _set_extended_scanner_channel
// LASpoint_set_extended_scanner_channel
// arg 0: U8 extended_scanner_channel
void LASpoint_set_extended_scanner_channel(WLASpoint* self, U8 extended_scanner_channel);
// Method F32 _get_scan_angle
// LASpoint_get_scan_angle
F32 LASpoint_get_scan_angle(WLASpoint* self);
// Method F32 _get_abs_scan_angle
// LASpoint_get_abs_scan_angle
F32 LASpoint_get_abs_scan_angle(WLASpoint* self);
// Method void _set_scan_angle
// LASpoint_set_scan_angle
// arg 0: F32 scan_angle
void LASpoint_set_scan_angle(WLASpoint* self, F32 scan_angle);
// Method void _compute_coordinates
// LASpoint_compute_coordinates
void LASpoint_compute_coordinates(WLASpoint* self);
// Method BOOL _compute_XYZ
// LASpoint_compute_XYZ
BOOL LASpoint_compute_XYZ(WLASpoint* self);
// Method BOOL _compute_XYZ
// LASpoint_compute_XYZ
// arg 0: const class LASquantizer * quantizer
BOOL LASpoint_compute_XYZ_1(WLASpoint* self, WLASquantizer* quantizer);
// Method BOOL _has_attribute
// LASpoint_has_attribute
// arg 0: U32 index
BOOL LASpoint_has_attribute(WLASpoint* self, U32 index);
// Method BOOL _get_attribute
// LASpoint_get_attribute
// arg 0: U32 index
// arg 1: U8 * data
BOOL LASpoint_get_attribute(WLASpoint* self, U32 index, U8 * data);
// Method BOOL _set_attribute
// LASpoint_set_attribute
// arg 0: U32 index
// arg 1: const U8 * data
BOOL LASpoint_set_attribute(WLASpoint* self, U32 index, const U8 * data);
// Method const CHAR * _get_attribute_name
// LASpoint_get_attribute_name
// arg 0: U32 index
const CHAR * LASpoint_get_attribute_name(WLASpoint* self, U32 index);
// Method F64 _get_attribute_as_float
// LASpoint_get_attribute_as_float
// arg 0: U32 index
F64 LASpoint_get_attribute_as_float(WLASpoint* self, U32 index);
// Method void _set_attribute_as_float
// LASpoint_set_attribute_as_float
// arg 0: U32 index
// arg 1: F64 value
void LASpoint_set_attribute_as_float(WLASpoint* self, U32 index, F64 value);
// Method void _get_attribute
// LASpoint_get_attribute
// arg 0: I32 start
// arg 1: U8 & data
void LASpoint_get_attribute_1(WLASpoint* self, I32 start, U8 & data);
// Method void _set_attribute
// LASpoint_set_attribute
// arg 0: I32 start
// arg 1: U8 data
void LASpoint_set_attribute_1(WLASpoint* self, I32 start, U8 data);
// Method void _get_attribute
// LASpoint_get_attribute
// arg 0: I32 start
// arg 1: I8 & data
void LASpoint_get_attribute_2(WLASpoint* self, I32 start, I8 & data);
// Method void _set_attribute
// LASpoint_set_attribute
// arg 0: I32 start
// arg 1: I8 data
void LASpoint_set_attribute_2(WLASpoint* self, I32 start, I8 data);
// Method void _get_attribute
// LASpoint_get_attribute
// arg 0: I32 start
// arg 1: U16 & data
void LASpoint_get_attribute_3(WLASpoint* self, I32 start, U16 & data);
// Method void _set_attribute
// LASpoint_set_attribute
// arg 0: I32 start
// arg 1: U16 data
void LASpoint_set_attribute_3(WLASpoint* self, I32 start, U16 data);
// Method void _get_attribute
// LASpoint_get_attribute
// arg 0: I32 start
// arg 1: I16 & data
void LASpoint_get_attribute_4(WLASpoint* self, I32 start, I16 & data);
// Method void _set_attribute
// LASpoint_set_attribute
// arg 0: I32 start
// arg 1: I16 data
void LASpoint_set_attribute_4(WLASpoint* self, I32 start, I16 data);
// Method void _get_attribute
// LASpoint_get_attribute
// arg 0: I32 start
// arg 1: U32 & data
void LASpoint_get_attribute_5(WLASpoint* self, I32 start, U32 & data);
// Method void _set_attribute
// LASpoint_set_attribute
// arg 0: I32 start
// arg 1: U32 data
void LASpoint_set_attribute_5(WLASpoint* self, I32 start, U32 data);
// Method void _get_attribute
// LASpoint_get_attribute
// arg 0: I32 start
// arg 1: I32 & data
void LASpoint_get_attribute_6(WLASpoint* self, I32 start, I32 & data);
// Method void _set_attribute
// LASpoint_set_attribute
// arg 0: I32 start
// arg 1: I32 data
void LASpoint_set_attribute_6(WLASpoint* self, I32 start, I32 data);
// Method void _get_attribute
// LASpoint_get_attribute
// arg 0: I32 start
// arg 1: U64 & data
void LASpoint_get_attribute_7(WLASpoint* self, I32 start, U64 & data);
// Method void _set_attribute
// LASpoint_set_attribute
// arg 0: I32 start
// arg 1: U64 data
void LASpoint_set_attribute_7(WLASpoint* self, I32 start, U64 data);
// Method void _get_attribute
// LASpoint_get_attribute
// arg 0: I32 start
// arg 1: I64 & data
void LASpoint_get_attribute_8(WLASpoint* self, I32 start, I64 & data);
// Method void _set_attribute
// LASpoint_set_attribute
// arg 0: I32 start
// arg 1: I64 data
void LASpoint_set_attribute_8(WLASpoint* self, I32 start, I64 data);
// Method void _get_attribute
// LASpoint_get_attribute
// arg 0: I32 start
// arg 1: F32 & data
void LASpoint_get_attribute_9(WLASpoint* self, I32 start, F32 & data);
// Method void _set_attribute
// LASpoint_set_attribute
// arg 0: I32 start
// arg 1: F32 data
void LASpoint_set_attribute_9(WLASpoint* self, I32 start, F32 data);
// Method void _get_attribute
// LASpoint_get_attribute
// arg 0: I32 start
// arg 1: F64 & data
void LASpoint_get_attribute_10(WLASpoint* self, I32 start, F64 & data);
// Method void _set_attribute
// LASpoint_set_attribute
// arg 0: I32 start
// arg 1: F64 data
void LASpoint_set_attribute_10(WLASpoint* self, I32 start, F64 data);
// LASpoint_destroy
void LASpoint_destroy(WLASpoint* self);
struct      WLASvlr;
typedef     struct WLASvlr WLASvlr;
// LASvlr_create
WLASvlr* LASvlr_create();
struct      WLASevlr;
typedef     struct WLASevlr WLASevlr;
// LASevlr_create
WLASevlr* LASevlr_create();
struct      WLASvlr_geo_keys;
typedef     struct WLASvlr_geo_keys WLASvlr_geo_keys;
struct      WLASvlr_key_entry;
typedef     struct WLASvlr_key_entry WLASvlr_key_entry;
struct      WLASvlr_classification;
typedef     struct WLASvlr_classification WLASvlr_classification;
struct      WLASvlr_wave_packet_descr;
typedef     struct WLASvlr_wave_packet_descr WLASvlr_wave_packet_descr;
// LASvlr_wave_packet_descr_create
WLASvlr_wave_packet_descr* LASvlr_wave_packet_descr_create();
// Method void _clean
// LASvlr_wave_packet_descr_clean
void LASvlr_wave_packet_descr_clean(WLASvlr_wave_packet_descr* self);
// Method U8 _getBitsPerSample
// LASvlr_wave_packet_descr_getBitsPerSample
U8 LASvlr_wave_packet_descr_getBitsPerSample(WLASvlr_wave_packet_descr* self);
// Method U8 _getCompressionType
// LASvlr_wave_packet_descr_getCompressionType
U8 LASvlr_wave_packet_descr_getCompressionType(WLASvlr_wave_packet_descr* self);
// Method U32 _getNumberOfSamples
// LASvlr_wave_packet_descr_getNumberOfSamples
U32 LASvlr_wave_packet_descr_getNumberOfSamples(WLASvlr_wave_packet_descr* self);
// Method U32 _getTemporalSpacing
// LASvlr_wave_packet_descr_getTemporalSpacing
U32 LASvlr_wave_packet_descr_getTemporalSpacing(WLASvlr_wave_packet_descr* self);
// Method F64 _getDigitizerGain
// LASvlr_wave_packet_descr_getDigitizerGain
F64 LASvlr_wave_packet_descr_getDigitizerGain(WLASvlr_wave_packet_descr* self);
// Method F64 _getDigitizerOffset
// LASvlr_wave_packet_descr_getDigitizerOffset
F64 LASvlr_wave_packet_descr_getDigitizerOffset(WLASvlr_wave_packet_descr* self);
// Method void _setBitsPerSample
// LASvlr_wave_packet_descr_setBitsPerSample
// arg 0: U8 bps
void LASvlr_wave_packet_descr_setBitsPerSample(WLASvlr_wave_packet_descr* self, U8 bps);
// Method void _setCompressionType
// LASvlr_wave_packet_descr_setCompressionType
// arg 0: U8 compression
void LASvlr_wave_packet_descr_setCompressionType(WLASvlr_wave_packet_descr* self, U8 compression);
// Method void _setNumberOfSamples
// LASvlr_wave_packet_descr_setNumberOfSamples
// arg 0: U32 samples
void LASvlr_wave_packet_descr_setNumberOfSamples(WLASvlr_wave_packet_descr* self, U32 samples);
// Method void _setTemporalSpacing
// LASvlr_wave_packet_descr_setTemporalSpacing
// arg 0: U32 spacing
void LASvlr_wave_packet_descr_setTemporalSpacing(WLASvlr_wave_packet_descr* self, U32 spacing);
// Method void _setDigitizerGain
// LASvlr_wave_packet_descr_setDigitizerGain
// arg 0: F64 gain
void LASvlr_wave_packet_descr_setDigitizerGain(WLASvlr_wave_packet_descr* self, F64 gain);
// Method void _setDigitizerOffset
// LASvlr_wave_packet_descr_setDigitizerOffset
// arg 0: F64 offset
void LASvlr_wave_packet_descr_setDigitizerOffset(WLASvlr_wave_packet_descr* self, F64 offset);
struct      WLASheader;
typedef     struct WLASheader WLASheader;
// LASheader_create
WLASheader* LASheader_create();
// Method void _set_bounding_box
// LASheader_set_bounding_box
// arg 0: F64 min_x
// arg 1: F64 min_y
// arg 2: F64 min_z
// arg 3: F64 max_x
// arg 4: F64 max_y
// arg 5: F64 max_z
// arg 6: BOOL auto_scale
// arg 7: BOOL auto_offset
void LASheader_set_bounding_box(WLASheader* self, F64 min_x, F64 min_y, F64 min_z, F64 max_x, F64 max_y, F64 max_z, BOOL auto_scale, BOOL auto_offset);
// Method void _set_global_encoding_bit
// LASheader_set_global_encoding_bit
// arg 0: I32 bit
void LASheader_set_global_encoding_bit(WLASheader* self, I32 bit);
// Method void _unset_global_encoding_bit
// LASheader_unset_global_encoding_bit
// arg 0: I32 bit
void LASheader_unset_global_encoding_bit(WLASheader* self, I32 bit);
// Method BOOL _get_global_encoding_bit
// LASheader_get_global_encoding_bit
// arg 0: I32 bit
BOOL LASheader_get_global_encoding_bit(WLASheader* self, I32 bit);
// Method void _clean_las_header
// LASheader_clean_las_header
void LASheader_clean_las_header(WLASheader* self);
// Method void _clean_user_data_in_header
// LASheader_clean_user_data_in_header
void LASheader_clean_user_data_in_header(WLASheader* self);
// Method void _clean_vlrs
// LASheader_clean_vlrs
void LASheader_clean_vlrs(WLASheader* self);
// Method void _clean_evlrs
// LASheader_clean_evlrs
void LASheader_clean_evlrs(WLASheader* self);
// Method void _clean_laszip
// LASheader_clean_laszip
void LASheader_clean_laszip(WLASheader* self);
// Method void _clean_lastiling
// LASheader_clean_lastiling
void LASheader_clean_lastiling(WLASheader* self);
// Method void _clean_lasoriginal
// LASheader_clean_lasoriginal
void LASheader_clean_lasoriginal(WLASheader* self);
// Method void _clean_user_data_after_header
// LASheader_clean_user_data_after_header
void LASheader_clean_user_data_after_header(WLASheader* self);
// Method void _clean
// LASheader_clean
void LASheader_clean(WLASheader* self);
// Method void _unlink
// LASheader_unlink
void LASheader_unlink(WLASheader* self);
// Method BOOL _check
// LASheader_check
BOOL LASheader_check(WLASheader* self);
// Method BOOL _is_compressed
// LASheader_is_compressed
BOOL LASheader_is_compressed(WLASheader* self);
// Method BOOL _is_lonlat
// LASheader_is_lonlat
// arg 0: const F32 extend
BOOL LASheader_is_lonlat(WLASheader* self, const F32 extend);
// Method BOOL _add_vlr
// LASheader_add_vlr
// arg 0: const CHAR * user_id
// arg 1: const U16 record_id
// arg 2: const U16 record_length_after_header
// arg 3: U8 * data
// arg 4: const BOOL keep_description
// arg 5: const CHAR * description
// arg 6: const BOOL keep_existing
BOOL LASheader_add_vlr(WLASheader* self, const CHAR * user_id, const U16 record_id, const U16 record_length_after_header, U8 * data, const BOOL keep_description, const CHAR * description, const BOOL keep_existing);
// Method const class LASvlr * _get_vlr
// LASheader_get_vlr
// arg 0: const CHAR * user_id
// arg 1: U16 record_id
WLASvlr* LASheader_get_vlr(WLASheader* self, const CHAR * user_id, U16 record_id);
// Method BOOL _remove_vlr
// LASheader_remove_vlr
// arg 0: U32 i
// arg 1: BOOL delete_data
BOOL LASheader_remove_vlr(WLASheader* self, U32 i, BOOL delete_data);
// Method BOOL _remove_vlr
// LASheader_remove_vlr
// arg 0: const CHAR * user_id
// arg 1: U16 record_id
BOOL LASheader_remove_vlr_1(WLASheader* self, const CHAR * user_id, U16 record_id);
// Method void _add_evlr
// LASheader_add_evlr
// arg 0: const CHAR * user_id
// arg 1: const U16 record_id
// arg 2: const I64 record_length_after_header
// arg 3: U8 * data
// arg 4: const BOOL keep_description
// arg 5: const CHAR * description
// arg 6: const BOOL keep_existing
void LASheader_add_evlr(WLASheader* self, const CHAR * user_id, const U16 record_id, const I64 record_length_after_header, U8 * data, const BOOL keep_description, const CHAR * description, const BOOL keep_existing);
// Method BOOL _remove_evlr
// LASheader_remove_evlr
// arg 0: U32 i
// arg 1: BOOL delete_data
BOOL LASheader_remove_evlr(WLASheader* self, U32 i, BOOL delete_data);
// Method BOOL _remove_evlr
// LASheader_remove_evlr
// arg 0: const CHAR * user_id
// arg 1: U16 record_id
BOOL LASheader_remove_evlr_1(WLASheader* self, const CHAR * user_id, U16 record_id);
// Method void _set_lastiling
// LASheader_set_lastiling
// arg 0: U32 level
// arg 1: U32 level_index
// arg 2: U32 implicit_levels
// arg 3: BOOL buffer
// arg 4: BOOL reversible
// arg 5: F32 min_x
// arg 6: F32 max_x
// arg 7: F32 min_y
// arg 8: F32 max_y
void LASheader_set_lastiling(WLASheader* self, U32 level, U32 level_index, U32 implicit_levels, BOOL buffer, BOOL reversible, F32 min_x, F32 max_x, F32 min_y, F32 max_y);
// Method void _set_lasoriginal
// LASheader_set_lasoriginal
void LASheader_set_lasoriginal(WLASheader* self);
// Method BOOL _restore_lasoriginal
// LASheader_restore_lasoriginal
BOOL LASheader_restore_lasoriginal(WLASheader* self);
// Method BOOL _set_geo_keys
// LASheader_set_geo_keys
// arg 0: const I32 number_of_keys
// arg 1: const class LASvlr_key_entry * geo_keys
BOOL LASheader_set_geo_keys(WLASheader* self, const I32 number_of_keys, WLASvlr_key_entry* geo_keys);
// Method BOOL _set_geo_double_params
// LASheader_set_geo_double_params
// arg 0: const I32 num_geo_double_params
// arg 1: const F64 * geo_double_params
BOOL LASheader_set_geo_double_params(WLASheader* self, const I32 num_geo_double_params, const F64 * geo_double_params);
// Method void _del_geo_double_params
// LASheader_del_geo_double_params
void LASheader_del_geo_double_params(WLASheader* self);
// Method BOOL _set_geo_ascii_params
// LASheader_set_geo_ascii_params
// arg 0: const I32 num_geo_ascii_params
// arg 1: const CHAR * geo_ascii_params
BOOL LASheader_set_geo_ascii_params(WLASheader* self, const I32 num_geo_ascii_params, const CHAR * geo_ascii_params);
// Method void _del_geo_ascii_params
// LASheader_del_geo_ascii_params
void LASheader_del_geo_ascii_params(WLASheader* self);
// Method void _set_geo_wkt_ogc_math
// LASheader_set_geo_wkt_ogc_math
// arg 0: const I32 num_geo_wkt_ogc_math
// arg 1: const CHAR * geo_wkt_ogc_math
void LASheader_set_geo_wkt_ogc_math(WLASheader* self, const I32 num_geo_wkt_ogc_math, const CHAR * geo_wkt_ogc_math);
// Method void _del_geo_wkt_ogc_math
// LASheader_del_geo_wkt_ogc_math
void LASheader_del_geo_wkt_ogc_math(WLASheader* self);
// Method void _set_geo_ogc_wkt
// LASheader_set_geo_ogc_wkt
// arg 0: const I32 num_geo_ogc_wkt
// arg 1: const CHAR * geo_ogc_wkt
// arg 2: BOOL in_evlr
void LASheader_set_geo_ogc_wkt(WLASheader* self, const I32 num_geo_ogc_wkt, const CHAR * geo_ogc_wkt, BOOL in_evlr);
// Method void _del_geo_ogc_wkt
// LASheader_del_geo_ogc_wkt
void LASheader_del_geo_ogc_wkt(WLASheader* self);
// Method BOOL _update_extra_bytes_vlr
// LASheader_update_extra_bytes_vlr
// arg 0: const BOOL keep_description
BOOL LASheader_update_extra_bytes_vlr(WLASheader* self, const BOOL keep_description);
// LASheader_destroy
void LASheader_destroy(WLASheader* self);
struct      WLASignore;
typedef     struct WLASignore WLASignore;
// Method void _usage
// LASignore_usage
void LASignore_usage(WLASignore* self);
// Method void _ignore_class
// LASignore_ignore_class
// arg 0: U8 classification
void LASignore_ignore_class(WLASignore* self, U8 classification);
// Method void _dont_ignore_class
// LASignore_dont_ignore_class
// arg 0: U8 classification
void LASignore_dont_ignore_class(WLASignore* self, U8 classification);
// Method BOOL _parse
// LASignore_parse
// arg 0: int & i
// arg 1: int argc
// arg 2: char ** argv
BOOL LASignore_parse(WLASignore* self, int & i, int argc, char ** argv);
// Method I32 _unparse
// LASignore_unparse
// arg 0: CHAR * string
I32 LASignore_unparse(WLASignore* self, CHAR * string);
// Method BOOL _parse
// LASignore_parse
// arg 0: U32 curr_parameter
// arg 1: const U32 num_parameters
// arg 2: const F64 * parameters
BOOL LASignore_parse_1(WLASignore* self, U32 curr_parameter, const U32 num_parameters, const F64 * parameters);
// Method void _unparse
// LASignore_unparse
// arg 0: U32 & num_parameters
// arg 1: F64 * parameters
void LASignore_unparse_1(WLASignore* self, U32 & num_parameters, F64 * parameters);
// Method U32 _get_decompress_selective
// LASignore_get_decompress_selective
U32 LASignore_get_decompress_selective(WLASignore* self);
// Method BOOL _ignore
// LASignore_ignore
// arg 0: const class LASpoint * point
BOOL LASignore_ignore(WLASignore* self, WLASpoint* point);
// LASignore_create
WLASignore* LASignore_create();
// LASignore_destroy
void LASignore_destroy(WLASignore* self);
struct      WLASindex;
typedef     struct WLASindex WLASindex;
struct      WLASfilter;
typedef     struct WLASfilter WLASfilter;
struct      WLAStransform;
typedef     struct WLAStransform WLAStransform;
struct      WLASkdtreeRectangles;
typedef     struct WLASkdtreeRectangles WLASkdtreeRectangles;
struct      WLASreader;
typedef     struct WLASreader WLASreader;
// Method I32 _get_format
// LASreader_get_format
I32 LASreader_get_format(WLASreader* self);
// Method BOOL _has_layers
// LASreader_has_layers
BOOL LASreader_has_layers(WLASreader* self);
// Method void _set_index
// LASreader_set_index
// arg 0: class LASindex * index
void LASreader_set_index(WLASreader* self, WLASindex* index);
// Method class LASindex * _get_index
// LASreader_get_index
WLASindex* LASreader_get_index(WLASreader* self);
// Method void _set_filter
// LASreader_set_filter
// arg 0: class LASfilter * filter
void LASreader_set_filter(WLASreader* self, WLASfilter* filter);
// Method class LASfilter * _get_filter
// LASreader_get_filter
WLASfilter* LASreader_get_filter(WLASreader* self);
// Method void _set_transform
// LASreader_set_transform
// arg 0: class LAStransform * transform
void LASreader_set_transform(WLASreader* self, WLAStransform* transform);
// Method class LAStransform * _get_transform
// LASreader_get_transform
WLAStransform* LASreader_get_transform(WLASreader* self);
// Method void _set_ignore
// LASreader_set_ignore
// arg 0: class LASignore * ignore
void LASreader_set_ignore(WLASreader* self, WLASignore* ignore);
// Method class LASignore * _get_ignore
// LASreader_get_ignore
WLASignore* LASreader_get_ignore(WLASreader* self);
// Method U32 _get_inside
// LASreader_get_inside
U32 LASreader_get_inside(WLASreader* self);
// Method BOOL _inside_none
// LASreader_inside_none
BOOL LASreader_inside_none(WLASreader* self);
// Method BOOL _inside_tile
// LASreader_inside_tile
// arg 0: const F32 ll_x
// arg 1: const F32 ll_y
// arg 2: const F32 size
BOOL LASreader_inside_tile(WLASreader* self, const F32 ll_x, const F32 ll_y, const F32 size);
// Method F32 _get_t_ll_x
// LASreader_get_t_ll_x
F32 LASreader_get_t_ll_x(WLASreader* self);
// Method F32 _get_t_ll_y
// LASreader_get_t_ll_y
F32 LASreader_get_t_ll_y(WLASreader* self);
// Method F32 _get_t_size
// LASreader_get_t_size
F32 LASreader_get_t_size(WLASreader* self);
// Method BOOL _inside_circle
// LASreader_inside_circle
// arg 0: const F64 center_x
// arg 1: const F64 center_y
// arg 2: const F64 radius
BOOL LASreader_inside_circle(WLASreader* self, const F64 center_x, const F64 center_y, const F64 radius);
// Method F64 _get_c_center_x
// LASreader_get_c_center_x
F64 LASreader_get_c_center_x(WLASreader* self);
// Method F64 _get_c_center_y
// LASreader_get_c_center_y
F64 LASreader_get_c_center_y(WLASreader* self);
// Method F64 _get_c_radius
// LASreader_get_c_radius
F64 LASreader_get_c_radius(WLASreader* self);
// Method BOOL _inside_rectangle
// LASreader_inside_rectangle
// arg 0: const F64 min_x
// arg 1: const F64 min_y
// arg 2: const F64 max_x
// arg 3: const F64 max_y
BOOL LASreader_inside_rectangle(WLASreader* self, const F64 min_x, const F64 min_y, const F64 max_x, const F64 max_y);
// Method F64 _get_r_min_x
// LASreader_get_r_min_x
F64 LASreader_get_r_min_x(WLASreader* self);
// Method F64 _get_r_min_y
// LASreader_get_r_min_y
F64 LASreader_get_r_min_y(WLASreader* self);
// Method F64 _get_r_max_x
// LASreader_get_r_max_x
F64 LASreader_get_r_max_x(WLASreader* self);
// Method F64 _get_r_max_y
// LASreader_get_r_max_y
F64 LASreader_get_r_max_y(WLASreader* self);
// Method BOOL _seek
// LASreader_seek
// arg 0: const I64 p_index
BOOL LASreader_seek(WLASreader* self, const I64 p_index);
// Method BOOL _read_point
// LASreader_read_point
BOOL LASreader_read_point(WLASreader* self);
// Method BOOL _ignore_point
// LASreader_ignore_point
BOOL LASreader_ignore_point(WLASreader* self);
// Method void _compute_coordinates
// LASreader_compute_coordinates
void LASreader_compute_coordinates(WLASreader* self);
// Method F64 _get_min_x
// LASreader_get_min_x
F64 LASreader_get_min_x(WLASreader* self);
// Method F64 _get_min_y
// LASreader_get_min_y
F64 LASreader_get_min_y(WLASreader* self);
// Method F64 _get_min_z
// LASreader_get_min_z
F64 LASreader_get_min_z(WLASreader* self);
// Method F64 _get_max_x
// LASreader_get_max_x
F64 LASreader_get_max_x(WLASreader* self);
// Method F64 _get_max_y
// LASreader_get_max_y
F64 LASreader_get_max_y(WLASreader* self);
// Method F64 _get_max_z
// LASreader_get_max_z
F64 LASreader_get_max_z(WLASreader* self);
// Method F64 _get_x
// LASreader_get_x
F64 LASreader_get_x(WLASreader* self);
// Method F64 _get_y
// LASreader_get_y
F64 LASreader_get_y(WLASreader* self);
// Method F64 _get_z
// LASreader_get_z
F64 LASreader_get_z(WLASreader* self);
// Method F64 _get_x
// LASreader_get_x
// arg 0: const I32 x
F64 LASreader_get_x_1(WLASreader* self, const I32 x);
// Method F64 _get_y
// LASreader_get_y
// arg 0: const I32 y
F64 LASreader_get_y_1(WLASreader* self, const I32 y);
// Method F64 _get_z
// LASreader_get_z
// arg 0: const I32 z
F64 LASreader_get_z_1(WLASreader* self, const I32 z);
// Method I64 _get_X
// LASreader_get_X
// arg 0: const F64 x
I64 LASreader_get_X(WLASreader* self, const F64 x);
// Method I64 _get_Y
// LASreader_get_Y
// arg 0: const F64 y
I64 LASreader_get_Y(WLASreader* self, const F64 y);
// Method I64 _get_Z
// LASreader_get_Z
// arg 0: const F64 z
I64 LASreader_get_Z(WLASreader* self, const F64 z);
// Method void _close
// LASreader_close
// arg 0: BOOL close_stream
void LASreader_close(WLASreader* self, BOOL close_stream);
// LASreader_create
WLASreader* LASreader_create();
// LASreader_destroy
void LASreader_destroy(WLASreader* self);
// Method void _dealloc
// LASreader_dealloc
void LASreader_dealloc(WLASreader* self);
struct      WLASwaveformDescription;
typedef     struct WLASwaveformDescription WLASwaveformDescription;
struct      WLASwaveform13reader;
typedef     struct WLASwaveform13reader WLASwaveform13reader;
// Method BOOL _open
// LASwaveform13reader_open
// arg 0: const char * file_name
// arg 1: I64 start_of_waveform_data_packet_record
// arg 2: const class LASvlr_wave_packet_descr *const * wave_packet_descr
BOOL LASwaveform13reader_open(WLASwaveform13reader* self, const char * file_name, I64 start_of_waveform_data_packet_record, const class LASvlr_wave_packet_descr *const * wave_packet_descr);
// Method BOOL _is_compressed
// LASwaveform13reader_is_compressed
BOOL LASwaveform13reader_is_compressed(WLASwaveform13reader* self);
// Method BOOL _read_waveform
// LASwaveform13reader_read_waveform
// arg 0: const class LASpoint * point
BOOL LASwaveform13reader_read_waveform(WLASwaveform13reader* self, WLASpoint* point);
// Method BOOL _get_samples
// LASwaveform13reader_get_samples
BOOL LASwaveform13reader_get_samples(WLASwaveform13reader* self);
// Method BOOL _has_samples
// LASwaveform13reader_has_samples
BOOL LASwaveform13reader_has_samples(WLASwaveform13reader* self);
// Method BOOL _get_samples_xyz
// LASwaveform13reader_get_samples_xyz
BOOL LASwaveform13reader_get_samples_xyz(WLASwaveform13reader* self);
// Method BOOL _has_samples_xyz
// LASwaveform13reader_has_samples_xyz
BOOL LASwaveform13reader_has_samples_xyz(WLASwaveform13reader* self);
// Method void _close
// LASwaveform13reader_close
void LASwaveform13reader_close(WLASwaveform13reader* self);
// LASwaveform13reader_create
WLASwaveform13reader* LASwaveform13reader_create();
// LASwaveform13reader_destroy
void LASwaveform13reader_destroy(WLASwaveform13reader* self);
struct      WLASreadOpener;
typedef     struct WLASreadOpener WLASreadOpener;
// Method void _set_io_ibuffer_size
// LASreadOpener_set_io_ibuffer_size
// arg 0: const U32 buffer_size
void LASreadOpener_set_io_ibuffer_size(WLASreadOpener* self, const U32 buffer_size);
// Method U32 _get_io_ibuffer_size
// LASreadOpener_get_io_ibuffer_size
U32 LASreadOpener_get_io_ibuffer_size(WLASreadOpener* self);
// Method U32 _get_file_name_number
// LASreadOpener_get_file_name_number
U32 LASreadOpener_get_file_name_number(WLASreadOpener* self);
// Method U32 _get_file_name_current
// LASreadOpener_get_file_name_current
U32 LASreadOpener_get_file_name_current(WLASreadOpener* self);
// Method const CHAR * _get_file_name
// LASreadOpener_get_file_name
const CHAR * LASreadOpener_get_file_name(WLASreadOpener* self);
// Method const CHAR * _get_file_name_only
// LASreadOpener_get_file_name_only
const CHAR * LASreadOpener_get_file_name_only(WLASreadOpener* self);
// Method const CHAR * _get_file_extension_only
// LASreadOpener_get_file_extension_only
const CHAR * LASreadOpener_get_file_extension_only(WLASreadOpener* self);
// Method const CHAR * _get_file_name
// LASreadOpener_get_file_name
// arg 0: U32 number
const CHAR * LASreadOpener_get_file_name_1(WLASreadOpener* self, U32 number);
// Method const CHAR * _get_file_name_only
// LASreadOpener_get_file_name_only
// arg 0: U32 number
const CHAR * LASreadOpener_get_file_name_only_1(WLASreadOpener* self, U32 number);
// Method const CHAR * _get_file_extension_only
// LASreadOpener_get_file_extension_only
// arg 0: U32 number
const CHAR * LASreadOpener_get_file_extension_only_1(WLASreadOpener* self, U32 number);
// Method CHAR * _get_file_name_base
// LASreadOpener_get_file_name_base
CHAR * LASreadOpener_get_file_name_base(WLASreadOpener* self);
// Method CHAR * _get_file_name_base
// LASreadOpener_get_file_name_base
// arg 0: U32 number
CHAR * LASreadOpener_get_file_name_base_1(WLASreadOpener* self, U32 number);
// Method void _set_file_name
// LASreadOpener_set_file_name
// arg 0: const CHAR * file_name
// arg 1: BOOL unique
void LASreadOpener_set_file_name(WLASreadOpener* self, const CHAR * file_name, BOOL unique);
// Method BOOL _add_file_name
// LASreadOpener_add_file_name
// arg 0: const CHAR * file_name
// arg 1: BOOL unique
BOOL LASreadOpener_add_file_name(WLASreadOpener* self, const CHAR * file_name, BOOL unique);
// Method BOOL _add_list_of_files
// LASreadOpener_add_list_of_files
// arg 0: const CHAR * list_of_files
// arg 1: BOOL unique
BOOL LASreadOpener_add_list_of_files(WLASreadOpener* self, const CHAR * list_of_files, BOOL unique);
// Method void _delete_file_name
// LASreadOpener_delete_file_name
// arg 0: U32 file_name_id
void LASreadOpener_delete_file_name(WLASreadOpener* self, U32 file_name_id);
// Method BOOL _set_file_name_current
// LASreadOpener_set_file_name_current
// arg 0: U32 file_name_id
BOOL LASreadOpener_set_file_name_current(WLASreadOpener* self, U32 file_name_id);
// Method I32 _get_file_format
// LASreadOpener_get_file_format
// arg 0: U32 number
I32 LASreadOpener_get_file_format(WLASreadOpener* self, U32 number);
// Method void _set_merged
// LASreadOpener_set_merged
// arg 0: const BOOL merged
void LASreadOpener_set_merged(WLASreadOpener* self, const BOOL merged);
// Method BOOL _is_merged
// LASreadOpener_is_merged
BOOL LASreadOpener_is_merged(WLASreadOpener* self);
// Method void _set_stored
// LASreadOpener_set_stored
// arg 0: const BOOL stored
void LASreadOpener_set_stored(WLASreadOpener* self, const BOOL stored);
// Method BOOL _is_stored
// LASreadOpener_is_stored
BOOL LASreadOpener_is_stored(WLASreadOpener* self);
// Method void _set_buffer_size
// LASreadOpener_set_buffer_size
// arg 0: const F32 buffer_size
void LASreadOpener_set_buffer_size(WLASreadOpener* self, const F32 buffer_size);
// Method F32 _get_buffer_size
// LASreadOpener_get_buffer_size
F32 LASreadOpener_get_buffer_size(WLASreadOpener* self);
// Method void _set_neighbor_file_name
// LASreadOpener_set_neighbor_file_name
// arg 0: const CHAR * neighbor_file_name
// arg 1: BOOL unique
void LASreadOpener_set_neighbor_file_name(WLASreadOpener* self, const CHAR * neighbor_file_name, BOOL unique);
// Method BOOL _add_neighbor_file_name
// LASreadOpener_add_neighbor_file_name
// arg 0: const CHAR * neighbor_file_name
// arg 1: BOOL unique
BOOL LASreadOpener_add_neighbor_file_name(WLASreadOpener* self, const CHAR * neighbor_file_name, BOOL unique);
// Method BOOL _add_neighbor_file_name
// LASreadOpener_add_neighbor_file_name
// arg 0: const CHAR * file_name
// arg 1: I64 npoints
// arg 2: F64 min_x
// arg 3: F64 min_y
// arg 4: F64 max_x
// arg 5: F64 max_y
// arg 6: BOOL unique
BOOL LASreadOpener_add_neighbor_file_name_1(WLASreadOpener* self, const CHAR * file_name, I64 npoints, F64 min_x, F64 min_y, F64 max_x, F64 max_y, BOOL unique);
// Method BOOL _add_neighbor_list_of_files
// LASreadOpener_add_neighbor_list_of_files
// arg 0: const CHAR * list_of_files
// arg 1: BOOL unique
BOOL LASreadOpener_add_neighbor_list_of_files(WLASreadOpener* self, const CHAR * list_of_files, BOOL unique);
// Method void _set_auto_reoffset
// LASreadOpener_set_auto_reoffset
// arg 0: const BOOL auto_reoffset
void LASreadOpener_set_auto_reoffset(WLASreadOpener* self, const BOOL auto_reoffset);
// Method BOOL _is_auto_reoffset
// LASreadOpener_is_auto_reoffset
BOOL LASreadOpener_is_auto_reoffset(WLASreadOpener* self);
// Method void _set_files_are_flightlines
// LASreadOpener_set_files_are_flightlines
// arg 0: const I32 files_are_flightlines
void LASreadOpener_set_files_are_flightlines(WLASreadOpener* self, const I32 files_are_flightlines);
// Method I32 _are_files_flightlines
// LASreadOpener_are_files_flightlines
I32 LASreadOpener_are_files_flightlines(WLASreadOpener* self);
// Method void _set_files_are_flightlines_index
// LASreadOpener_set_files_are_flightlines_index
// arg 0: const I32 files_are_flightlines_index
void LASreadOpener_set_files_are_flightlines_index(WLASreadOpener* self, const I32 files_are_flightlines_index);
// Method I32 _get_files_flight_index
// LASreadOpener_get_files_flight_index
I32 LASreadOpener_get_files_flight_index(WLASreadOpener* self);
// Method void _set_apply_file_source_ID
// LASreadOpener_set_apply_file_source_ID
// arg 0: const BOOL apply_file_source_ID
void LASreadOpener_set_apply_file_source_ID(WLASreadOpener* self, const BOOL apply_file_source_ID);
// Method BOOL _applying_file_source_ID
// LASreadOpener_applying_file_source_ID
BOOL LASreadOpener_applying_file_source_ID(WLASreadOpener* self);
// Method void _set_scale_factor
// LASreadOpener_set_scale_factor
// arg 0: const F64 * scale_factor
void LASreadOpener_set_scale_factor(WLASreadOpener* self, const F64 * scale_factor);
// Method const F64 * _get_scale_factor
// LASreadOpener_get_scale_factor
const F64 * LASreadOpener_get_scale_factor(WLASreadOpener* self);
// Method void _set_offset
// LASreadOpener_set_offset
// arg 0: const F64 * offset
void LASreadOpener_set_offset(WLASreadOpener* self, const F64 * offset);
// Method const F64 * _get_offset
// LASreadOpener_get_offset
const F64 * LASreadOpener_get_offset(WLASreadOpener* self);
// Method void _set_translate_intensity
// LASreadOpener_set_translate_intensity
// arg 0: const F32 translation
void LASreadOpener_set_translate_intensity(WLASreadOpener* self, const F32 translation);
// Method void _set_scale_intensity
// LASreadOpener_set_scale_intensity
// arg 0: const F32 scale
void LASreadOpener_set_scale_intensity(WLASreadOpener* self, const F32 scale);
// Method void _set_translate_scan_angle
// LASreadOpener_set_translate_scan_angle
// arg 0: const F32 translate_scan_angle
void LASreadOpener_set_translate_scan_angle(WLASreadOpener* self, const F32 translate_scan_angle);
// Method void _set_scale_scan_angle
// LASreadOpener_set_scale_scan_angle
// arg 0: const F32 scale_scan_angle
void LASreadOpener_set_scale_scan_angle(WLASreadOpener* self, const F32 scale_scan_angle);
// Method void _add_attribute
// LASreadOpener_add_attribute
// arg 0: I32 data_type
// arg 1: const CHAR * name
// arg 2: const CHAR * description
// arg 3: F64 scale
// arg 4: F64 offset
// arg 5: F64 pre_scale
// arg 6: F64 pre_offset
// arg 7: F64 no_data
void LASreadOpener_add_attribute(WLASreadOpener* self, I32 data_type, const CHAR * name, const CHAR * description, F64 scale, F64 offset, F64 pre_scale, F64 pre_offset, F64 no_data);
// Method BOOL _set_point_type
// LASreadOpener_set_point_type
// arg 0: U8 point_type
BOOL LASreadOpener_set_point_type(WLASreadOpener* self, U8 point_type);
// Method void _set_parse_string
// LASreadOpener_set_parse_string
// arg 0: const CHAR * parse_string
void LASreadOpener_set_parse_string(WLASreadOpener* self, const CHAR * parse_string);
// Method void _set_skip_lines
// LASreadOpener_set_skip_lines
// arg 0: const U32 number_of_lines
void LASreadOpener_set_skip_lines(WLASreadOpener* self, const U32 number_of_lines);
// Method void _set_populate_header
// LASreadOpener_set_populate_header
// arg 0: BOOL populate_header
void LASreadOpener_set_populate_header(WLASreadOpener* self, BOOL populate_header);
// Method void _set_keep_lastiling
// LASreadOpener_set_keep_lastiling
// arg 0: BOOL keep_lastiling
void LASreadOpener_set_keep_lastiling(WLASreadOpener* self, BOOL keep_lastiling);
// Method void _set_pipe_on
// LASreadOpener_set_pipe_on
// arg 0: BOOL pipe_on
void LASreadOpener_set_pipe_on(WLASreadOpener* self, BOOL pipe_on);
// Method const CHAR * _get_parse_string
// LASreadOpener_get_parse_string
const CHAR * LASreadOpener_get_parse_string(WLASreadOpener* self);
// Method void _usage
// LASreadOpener_usage
void LASreadOpener_usage(WLASreadOpener* self);
// Method void _set_decompress_selective
// LASreadOpener_set_decompress_selective
// arg 0: U32 decompress_selective
void LASreadOpener_set_decompress_selective(WLASreadOpener* self, U32 decompress_selective);
// Method void _set_inside_tile
// LASreadOpener_set_inside_tile
// arg 0: const F32 ll_x
// arg 1: const F32 ll_y
// arg 2: const F32 size
void LASreadOpener_set_inside_tile(WLASreadOpener* self, const F32 ll_x, const F32 ll_y, const F32 size);
// Method void _set_inside_circle
// LASreadOpener_set_inside_circle
// arg 0: const F64 center_x
// arg 1: const F64 center_y
// arg 2: const F64 radius
void LASreadOpener_set_inside_circle(WLASreadOpener* self, const F64 center_x, const F64 center_y, const F64 radius);
// Method void _set_inside_rectangle
// LASreadOpener_set_inside_rectangle
// arg 0: const F64 min_x
// arg 1: const F64 min_y
// arg 2: const F64 max_x
// arg 3: const F64 max_y
void LASreadOpener_set_inside_rectangle(WLASreadOpener* self, const F64 min_x, const F64 min_y, const F64 max_x, const F64 max_y);
// Method BOOL _parse
// LASreadOpener_parse
// arg 0: int argc
// arg 1: char ** argv
// arg 2: BOOL parse_ignore
BOOL LASreadOpener_parse(WLASreadOpener* self, int argc, char ** argv, BOOL parse_ignore);
// Method BOOL _is_piped
// LASreadOpener_is_piped
BOOL LASreadOpener_is_piped(WLASreadOpener* self);
// Method BOOL _is_buffered
// LASreadOpener_is_buffered
BOOL LASreadOpener_is_buffered(WLASreadOpener* self);
// Method BOOL _is_header_populated
// LASreadOpener_is_header_populated
BOOL LASreadOpener_is_header_populated(WLASreadOpener* self);
// Method BOOL _active
// LASreadOpener_active
BOOL LASreadOpener_active(WLASreadOpener* self);
// Method BOOL _is_inside
// LASreadOpener_is_inside
BOOL LASreadOpener_is_inside(WLASreadOpener* self);
// Method I32 _unparse
// LASreadOpener_unparse
// arg 0: CHAR * string
I32 LASreadOpener_unparse(WLASreadOpener* self, CHAR * string);
// Method void _set_filter
// LASreadOpener_set_filter
// arg 0: class LASfilter * filter
void LASreadOpener_set_filter(WLASreadOpener* self, WLASfilter* filter);
// Method class LASfilter * _get_filter
// LASreadOpener_get_filter
WLASfilter* LASreadOpener_get_filter(WLASreadOpener* self);
// Method void _set_transform
// LASreadOpener_set_transform
// arg 0: class LAStransform * transform
void LASreadOpener_set_transform(WLASreadOpener* self, WLAStransform* transform);
// Method class LAStransform * _get_transform
// LASreadOpener_get_transform
WLAStransform* LASreadOpener_get_transform(WLASreadOpener* self);
// Method void _set_ignore
// LASreadOpener_set_ignore
// arg 0: class LASignore * ignore
void LASreadOpener_set_ignore(WLASreadOpener* self, WLASignore* ignore);
// Method class LASignore * _get_ignore
// LASreadOpener_get_ignore
WLASignore* LASreadOpener_get_ignore(WLASreadOpener* self);
// Method void _reset
// LASreadOpener_reset
void LASreadOpener_reset(WLASreadOpener* self);
// Method const CHAR * _get_temp_file_base
// LASreadOpener_get_temp_file_base
const CHAR * LASreadOpener_get_temp_file_base(WLASreadOpener* self);
// Method class LASreader * _open
// LASreadOpener_open
// arg 0: const CHAR * other_file_name
// arg 1: BOOL reset_after_other
WLASreader* LASreadOpener_open(WLASreadOpener* self, const CHAR * other_file_name, BOOL reset_after_other);
// Method BOOL _reopen
// LASreadOpener_reopen
// arg 0: class LASreader * lasreader
// arg 1: BOOL remain_buffered
BOOL LASreadOpener_reopen(WLASreadOpener* self, WLASreader* lasreader, BOOL remain_buffered);
// Method class LASwaveform13reader * _open_waveform13
// LASreadOpener_open_waveform13
// arg 0: const class LASheader * lasheader
WLASwaveform13reader* LASreadOpener_open_waveform13(WLASreadOpener* self, WLASheader* lasheader);
// Method I32 _get_number_attributes
// LASreadOpener_get_number_attributes
I32 LASreadOpener_get_number_attributes(WLASreadOpener* self);
// Method I32 _get_attribute_data_type
// LASreadOpener_get_attribute_data_type
// arg 0: U32 index
I32 LASreadOpener_get_attribute_data_type(WLASreadOpener* self, U32 index);
// Method const CHAR * _get_attribute_name
// LASreadOpener_get_attribute_name
// arg 0: U32 index
const CHAR * LASreadOpener_get_attribute_name(WLASreadOpener* self, U32 index);
// Method const CHAR * _get_attribute_description
// LASreadOpener_get_attribute_description
// arg 0: U32 index
const CHAR * LASreadOpener_get_attribute_description(WLASreadOpener* self, U32 index);
// Method F64 _get_attribute_scale
// LASreadOpener_get_attribute_scale
// arg 0: U32 index
F64 LASreadOpener_get_attribute_scale(WLASreadOpener* self, U32 index);
// Method F64 _get_attribute_offset
// LASreadOpener_get_attribute_offset
// arg 0: U32 index
F64 LASreadOpener_get_attribute_offset(WLASreadOpener* self, U32 index);
// Method F64 _get_attribute_no_data
// LASreadOpener_get_attribute_no_data
// arg 0: U32 index
F64 LASreadOpener_get_attribute_no_data(WLASreadOpener* self, U32 index);
// LASreadOpener_create
WLASreadOpener* LASreadOpener_create();
// LASreadOpener_destroy
void LASreadOpener_destroy(WLASreadOpener* self);
struct      WLASreadPoint;
typedef     struct WLASreadPoint WLASreadPoint;
struct      WLASreaderLAS;
typedef     struct WLASreaderLAS WLASreaderLAS;
// Method void _set_delete_stream
// LASreaderLAS_set_delete_stream
// arg 0: BOOL delete_stream
void LASreaderLAS_set_delete_stream(WLASreaderLAS* self, BOOL delete_stream);
// Method BOOL _open
// LASreaderLAS_open
// arg 0: const char * file_name
// arg 1: I32 io_buffer_size
// arg 2: BOOL peek_only
// arg 3: U32 decompress_selective
BOOL LASreaderLAS_open(WLASreaderLAS* self, const char * file_name, I32 io_buffer_size, BOOL peek_only, U32 decompress_selective);
// Method I32 _get_format
// LASreaderLAS_get_format
I32 LASreaderLAS_get_format(WLASreaderLAS* self);
// Method BOOL _seek
// LASreaderLAS_seek
// arg 0: const I64 p_index
BOOL LASreaderLAS_seek(WLASreaderLAS* self, const I64 p_index);
// Method void _close
// LASreaderLAS_close
// arg 0: BOOL close_stream
void LASreaderLAS_close(WLASreaderLAS* self, BOOL close_stream);
// LASreaderLAS_create
WLASreaderLAS* LASreaderLAS_create();
// LASreaderLAS_destroy
void LASreaderLAS_destroy(WLASreaderLAS* self);
struct      WLASreaderLASrescale;
typedef     struct WLASreaderLASrescale WLASreaderLASrescale;
// LASreaderLASrescale_create
// arg 0: F64 x_scale_factor
// arg 1: F64 y_scale_factor
// arg 2: F64 z_scale_factor
// arg 3: BOOL check_for_overflow
WLASreaderLASrescale* LASreaderLASrescale_create(F64 x_scale_factor, F64 y_scale_factor, F64 z_scale_factor, BOOL check_for_overflow);
struct      WLASreaderLASreoffset;
typedef     struct WLASreaderLASreoffset WLASreaderLASreoffset;
// LASreaderLASreoffset_create
// arg 0: F64 x_offset
// arg 1: F64 y_offset
// arg 2: F64 z_offset
WLASreaderLASreoffset* LASreaderLASreoffset_create(F64 x_offset, F64 y_offset, F64 z_offset);
// LASreaderLASreoffset_create
WLASreaderLASreoffset* LASreaderLASreoffset_create_1();
struct      WLASreaderLASrescalereoffset;
typedef     struct WLASreaderLASrescalereoffset WLASreaderLASrescalereoffset;
// LASreaderLASrescalereoffset_create
// arg 0: F64 x_scale_factor
// arg 1: F64 y_scale_factor
// arg 2: F64 z_scale_factor
// arg 3: F64 x_offset
// arg 4: F64 y_offset
// arg 5: F64 z_offset
WLASreaderLASrescalereoffset* LASreaderLASrescalereoffset_create(F64 x_scale_factor, F64 y_scale_factor, F64 z_scale_factor, F64 x_offset, F64 y_offset, F64 z_offset);
// LASreaderLASrescalereoffset_create
// arg 0: F64 x_scale_factor
// arg 1: F64 y_scale_factor
// arg 2: F64 z_scale_factor
WLASreaderLASrescalereoffset* LASreaderLASrescalereoffset_create_1(F64 x_scale_factor, F64 y_scale_factor, F64 z_scale_factor);

#ifdef __cplusplus
}
#endif
#endif /* CWRAPPER_H_ */
