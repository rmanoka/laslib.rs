#ifndef __CWRAPPER_H
#define __CWRAPPER_H_
#ifdef __cplusplus
extern "C"{
#endif


// LASvlr_lastiling
unsigned int *LASvlr_lastiling_field_level(void *self);
unsigned int *LASvlr_lastiling_field_level_index(void *self);
float *LASvlr_lastiling_field_min_x(void *self);
float *LASvlr_lastiling_field_max_x(void *self);
float *LASvlr_lastiling_field_min_y(void *self);
float *LASvlr_lastiling_field_max_y(void *self);
void *LASvlr_lastiling_create();


// LASvlr_lasoriginal
long long *LASvlr_lasoriginal_field_number_of_point_records(void *self);
void *LASvlr_lasoriginal_field_number_of_points_by_return(void *self);
double *LASvlr_lasoriginal_field_max_x(void *self);
double *LASvlr_lasoriginal_field_min_x(void *self);
double *LASvlr_lasoriginal_field_max_y(void *self);
double *LASvlr_lasoriginal_field_min_y(void *self);
double *LASvlr_lasoriginal_field_max_z(void *self);
double *LASvlr_lasoriginal_field_min_z(void *self);
long long *LASvlr_lasoriginal_field_position(void *self);
void *LASvlr_lasoriginal_create();


// LASitem
void *LASitem_field_type(void *self);
unsigned short *LASitem_field_size(void *self);
unsigned short *LASitem_field_version(void *self);
const void * LASitem_get_name(void *self);


// LASzip
bool LASzip_check_compressor(void *self, const unsigned short compressor);
bool LASzip_check_coder(void *self, const unsigned short coder);
bool LASzip_check_item(void *self, const void * item);
bool LASzip_check_items(void *self, const unsigned short num_items, const void * items, const unsigned short point_size);
bool LASzip_check(void *self, const unsigned short point_size);
bool LASzip_setup(void *self, void * num_items, void * items, const unsigned char point_type, const unsigned short point_size, const unsigned short compressor);
bool LASzip_is_standard(void *self, const unsigned short num_items, const void * items, void * point_type, void * record_length);
bool LASzip_is_standard_1(void *self, void * point_type, void * record_length);
void *LASzip_field_bytes(void *self);
bool LASzip_unpack(void *self, const void * bytes, const int num);
bool LASzip_request_compatibility_mode(void *self, const unsigned short requested_compatibility_mode);
bool LASzip_setup_1(void *self, const unsigned char point_type, const unsigned short point_size, const unsigned short compressor);
bool LASzip_setup_2(void *self, const unsigned short num_items, const void * items, const unsigned short compressor);
bool LASzip_set_chunk_size(void *self, const unsigned int chunk_size);
bool LASzip_request_version(void *self, const unsigned short requested_version);
const void * LASzip_get_error(void *self);
unsigned short *LASzip_field_compressor(void *self);
unsigned short *LASzip_field_coder(void *self);
unsigned char *LASzip_field_version_major(void *self);
unsigned char *LASzip_field_version_minor(void *self);
unsigned short *LASzip_field_version_revision(void *self);
unsigned int *LASzip_field_options(void *self);
unsigned int *LASzip_field_chunk_size(void *self);
long long *LASzip_field_number_of_special_evlrs(void *self);
long long *LASzip_field_offset_to_special_evlrs(void *self);
unsigned short *LASzip_field_num_items(void *self);
void *LASzip_field_items(void *self);
void *LASzip_create();
void LASzip_destroy(void *self);


// LASquantizer
double *LASquantizer_field_x_scale_factor(void *self);
double *LASquantizer_field_y_scale_factor(void *self);
double *LASquantizer_field_z_scale_factor(void *self);
double *LASquantizer_field_x_offset(void *self);
double *LASquantizer_field_y_offset(void *self);
double *LASquantizer_field_z_offset(void *self);
double LASquantizer_get_x(void *self, const int X);
double LASquantizer_get_y(void *self, const int Y);
double LASquantizer_get_z(void *self, const int Z);
long long LASquantizer_get_X(void *self, const double x);
long long LASquantizer_get_Y(void *self, const double y);
long long LASquantizer_get_Z(void *self, const double z);
void *LASquantizer_create();


// LASattribute
void *LASattribute_field_reserved(void *self);
unsigned char *LASattribute_field_data_type(void *self);
unsigned char *LASattribute_field_options(void *self);
void *LASattribute_field_name(void *self);
void *LASattribute_field_unused(void *self);
void *LASattribute_field_no_data(void *self);
void *LASattribute_field_min(void *self);
void *LASattribute_field_max(void *self);
void *LASattribute_field_scale(void *self);
void *LASattribute_field_offset(void *self);
void *LASattribute_field_description(void *self);
void *LASattribute_create(unsigned char size);
void *LASattribute_create_1(unsigned int type, const void * name, const void * description);
bool LASattribute_set_no_data(void *self, unsigned char no_data);
bool LASattribute_set_no_data_1(void *self, char no_data);
bool LASattribute_set_no_data_2(void *self, unsigned short no_data);
bool LASattribute_set_no_data_3(void *self, short no_data);
bool LASattribute_set_no_data_4(void *self, unsigned int no_data);
bool LASattribute_set_no_data_5(void *self, int no_data);
bool LASattribute_set_no_data_6(void *self, unsigned long long no_data);
bool LASattribute_set_no_data_7(void *self, long long no_data);
bool LASattribute_set_no_data_8(void *self, float no_data);
bool LASattribute_set_no_data_9(void *self, double no_data);
void LASattribute_set_min(void *self, void * min);
void LASattribute_update_min(void *self, void * min);
bool LASattribute_set_min_1(void *self, unsigned char min);
bool LASattribute_set_min_2(void *self, char min);
bool LASattribute_set_min_3(void *self, unsigned short min);
bool LASattribute_set_min_4(void *self, short min);
bool LASattribute_set_min_5(void *self, unsigned int min);
bool LASattribute_set_min_6(void *self, int min);
bool LASattribute_set_min_7(void *self, unsigned long long min);
bool LASattribute_set_min_8(void *self, long long min);
bool LASattribute_set_min_9(void *self, float min);
bool LASattribute_set_min_10(void *self, double min);
void LASattribute_set_max(void *self, void * max);
void LASattribute_update_max(void *self, void * max);
bool LASattribute_set_max_1(void *self, unsigned char max);
bool LASattribute_set_max_2(void *self, char max);
bool LASattribute_set_max_3(void *self, unsigned short max);
bool LASattribute_set_max_4(void *self, short max);
bool LASattribute_set_max_5(void *self, unsigned int max);
bool LASattribute_set_max_6(void *self, int max);
bool LASattribute_set_max_7(void *self, unsigned long long max);
bool LASattribute_set_max_8(void *self, long long max);
bool LASattribute_set_max_9(void *self, float max);
bool LASattribute_set_max_10(void *self, double max);
bool LASattribute_set_scale(void *self, double scale);
bool LASattribute_set_offset(void *self, double offset);
bool LASattribute_unset_scale(void *self);
bool LASattribute_unset_offset(void *self);
bool LASattribute_has_no_data(void *self);
bool LASattribute_has_min(void *self);
bool LASattribute_has_max(void *self);
bool LASattribute_has_scale(void *self);
bool LASattribute_has_offset(void *self);
unsigned int LASattribute_get_size(void *self);
double LASattribute_get_value_as_float(void *self, void * pointer);
void LASattribute_set_value_as_float(void *self, void * pointer, double value);


// LASattributer
bool *LASattributer_field_attributes_linked(void *self);
int *LASattributer_field_number_attributes(void *self);
void *LASattributer_field_attributes(void *self);
void *LASattributer_field_attribute_starts(void *self);
void *LASattributer_field_attribute_sizes(void *self);
void *LASattributer_create();
void LASattributer_destroy(void *self);
void LASattributer_clean_attributes(void *self);
bool LASattributer_init_attributes(void *self, unsigned int number_attributes, void * attributes);
short LASattributer_get_attributes_size(void *self);
int LASattributer_get_attribute_index(void *self, const void * name);
int LASattributer_get_attribute_start(void *self, const void * name);
int LASattributer_get_attribute_start_1(void *self, int index);
int LASattributer_get_attribute_size(void *self, int index);
const void * LASattributer_get_attribute_name(void *self, int index);
bool LASattributer_remove_attribute(void *self, int index);
bool LASattributer_remove_attribute_1(void *self, const void * name);


// LASwavepacket
void *LASwavepacket_create();
void LASwavepacket_zero(void *self);
unsigned char LASwavepacket_getIndex(void *self);
unsigned long long LASwavepacket_getOffset(void *self);
unsigned int LASwavepacket_getSize(void *self);
float LASwavepacket_getLocation(void *self);
float LASwavepacket_getXt(void *self);
float LASwavepacket_getYt(void *self);
float LASwavepacket_getZt(void *self);
void LASwavepacket_setIndex(void *self, unsigned char index);
void LASwavepacket_setOffset(void *self, unsigned long long offset);
void LASwavepacket_setSize(void *self, unsigned int size);
void LASwavepacket_setLocation(void *self, float location);
void LASwavepacket_setXt(void *self, float xt);
void LASwavepacket_setYt(void *self, float yt);
void LASwavepacket_setZt(void *self, float zt);
void LASwavepacket_flipDirection(void *self);


// LASpoint
int *LASpoint_field_X(void *self);
int *LASpoint_field_Y(void *self);
int *LASpoint_field_Z(void *self);
unsigned short *LASpoint_field_intensity(void *self);
char *LASpoint_field_scan_angle_rank(void *self);
unsigned char *LASpoint_field_user_data(void *self);
unsigned short *LASpoint_field_point_source_ID(void *self);
short *LASpoint_field_extended_scan_angle(void *self);
unsigned char *LASpoint_field_extended_classification(void *self);
unsigned char *LASpoint_field_deleted_flag(void *self);
void *LASpoint_field_dummy(void *self);
bool *LASpoint_field_gps_time_change(void *self);
double *LASpoint_field_gps_time(void *self);
void *LASpoint_field_rgb(void *self);
void *LASpoint_field_wavepacket(void *self);
void *LASpoint_field_extra_bytes(void *self);
void *LASpoint_field_quantizer(void *self);
void *LASpoint_field_coordinates(void *self);
void *LASpoint_field_attributer(void *self);
void *LASpoint_field_point(void *self);
bool *LASpoint_field_have_gps_time(void *self);
bool *LASpoint_field_have_rgb(void *self);
bool *LASpoint_field_have_nir(void *self);
bool *LASpoint_field_have_wavepacket(void *self);
int *LASpoint_field_extra_bytes_number(void *self);
unsigned int *LASpoint_field_total_point_size(void *self);
unsigned short *LASpoint_field_num_items(void *self);
void *LASpoint_field_items(void *self);
void LASpoint_copy_to(void *self, void * buffer);
void LASpoint_copy_from(void *self, const void * buffer);
bool LASpoint_init(void *self, const void * quantizer, const unsigned char point_type, const unsigned short point_size, const void * attributer);
bool LASpoint_init_1(void *self, const void * quantizer, const unsigned int num_items, const void * items, const void * attributer);
bool LASpoint_inside_rectangle(void *self, const double r_min_x, const double r_min_y, const double r_max_x, const double r_max_y);
bool LASpoint_inside_tile(void *self, const float ll_x, const float ll_y, const float ur_x, const float ur_y);
bool LASpoint_inside_circle(void *self, const double center_x, const double center_y, double squared_radius);
bool LASpoint_inside_box(void *self, const double min_x, const double min_y, const double min_z, const double max_x, const double max_y, const double max_z);
bool LASpoint_inside_bounding_box(void *self, const double min_x, const double min_y, const double min_z, const double max_x, const double max_y, const double max_z);
bool LASpoint_is_zero(void *self);
void LASpoint_zero(void *self);
void LASpoint_clean(void *self);
void *LASpoint_create();
bool LASpoint_is_first(void *self);
bool LASpoint_is_intermediate(void *self);
bool LASpoint_is_last(void *self);
bool LASpoint_is_single(void *self);
bool LASpoint_is_first_of_many(void *self);
bool LASpoint_is_last_of_many(void *self);
int LASpoint_get_X(void *self);
int LASpoint_get_Y(void *self);
int LASpoint_get_Z(void *self);
unsigned short LASpoint_get_intensity(void *self);
unsigned char LASpoint_get_return_number(void *self);
unsigned char LASpoint_get_number_of_returns(void *self);
unsigned char LASpoint_get_scan_direction_flag(void *self);
unsigned char LASpoint_get_edge_of_flight_line(void *self);
unsigned char LASpoint_get_classification(void *self);
unsigned char LASpoint_get_synthetic_flag(void *self);
unsigned char LASpoint_get_keypoint_flag(void *self);
unsigned char LASpoint_get_withheld_flag(void *self);
char LASpoint_get_scan_angle_rank(void *self);
unsigned char LASpoint_get_user_data(void *self);
unsigned short LASpoint_get_point_source_ID(void *self);
unsigned char LASpoint_get_deleted_flag(void *self);
double LASpoint_get_gps_time(void *self);
const void * LASpoint_get_RGB(void *self);
const void * LASpoint_get_RGBI(void *self);
unsigned short LASpoint_get_RGBI_1(void *self, const unsigned int band);
unsigned short LASpoint_get_R(void *self);
unsigned short LASpoint_get_G(void *self);
unsigned short LASpoint_get_B(void *self);
unsigned short LASpoint_get_I(void *self);
unsigned short LASpoint_get_NIR(void *self);
void LASpoint_set_X(void *self, const int X);
void LASpoint_set_Y(void *self, const int Y);
void LASpoint_set_Z(void *self, const int Z);
void LASpoint_set_intensity(void *self, const unsigned short intensity);
void LASpoint_set_return_number(void *self, const unsigned char return_number);
void LASpoint_set_number_of_returns(void *self, const unsigned char number_of_returns);
void LASpoint_set_scan_direction_flag(void *self, const unsigned char scan_direction_flag);
void LASpoint_set_edge_of_flight_line(void *self, const unsigned char edge_of_flight_line);
void LASpoint_set_classification(void *self, unsigned char classification);
void LASpoint_set_synthetic_flag(void *self, unsigned char synthetic_flag);
void LASpoint_set_keypoint_flag(void *self, unsigned char keypoint_flag);
void LASpoint_set_withheld_flag(void *self, unsigned char withheld_flag);
void LASpoint_set_scan_angle_rank(void *self, char scan_angle_rank);
void LASpoint_set_user_data(void *self, unsigned char user_data);
void LASpoint_set_point_source_ID(void *self, unsigned short point_source_ID);
void LASpoint_set_deleted_flag(void *self, unsigned char deleted_flag);
void LASpoint_set_gps_time(void *self, const double gps_time);
void LASpoint_set_RGB(void *self, const void * rgb);
void LASpoint_set_RGBI(void *self, const void * rgb);
void LASpoint_set_RGBI_1(void *self, const unsigned int band, const unsigned short value);
void LASpoint_set_R(void *self, const unsigned short R);
void LASpoint_set_G(void *self, const unsigned short G);
void LASpoint_set_B(void *self, const unsigned short B);
void LASpoint_set_I(void *self, const unsigned short I);
void LASpoint_set_NIR(void *self, const unsigned short NIR);
double LASpoint_get_x(void *self);
double LASpoint_get_y(void *self);
double LASpoint_get_z(void *self);
bool LASpoint_set_x(void *self, const double x);
bool LASpoint_set_y(void *self, const double y);
bool LASpoint_set_z(void *self, const double z);
bool LASpoint_is_extended_point_type(void *self);
unsigned char LASpoint_get_extended_classification(void *self);
unsigned char LASpoint_get_extended_return_number(void *self);
unsigned char LASpoint_get_extended_number_of_returns(void *self);
short LASpoint_get_extended_scan_angle(void *self);
unsigned char LASpoint_get_extended_overlap_flag(void *self);
unsigned char LASpoint_get_extended_scanner_channel(void *self);
void LASpoint_set_extended_classification(void *self, unsigned char extended_classification);
void LASpoint_set_extended_return_number(void *self, unsigned char extended_return_number);
void LASpoint_set_extended_number_of_returns(void *self, unsigned char extended_number_of_returns);
void LASpoint_set_extended_scan_angle(void *self, short extended_scan_angle);
void LASpoint_set_extended_overlap_flag(void *self, unsigned char extended_overlap_flag);
void LASpoint_set_extended_scanner_channel(void *self, unsigned char extended_scanner_channel);
float LASpoint_get_scan_angle(void *self);
float LASpoint_get_abs_scan_angle(void *self);
void LASpoint_set_scan_angle(void *self, float scan_angle);
void LASpoint_compute_coordinates(void *self);
bool LASpoint_compute_XYZ(void *self);
bool LASpoint_compute_XYZ_1(void *self, const void * quantizer);
bool LASpoint_has_attribute(void *self, unsigned int index);
bool LASpoint_get_attribute(void *self, unsigned int index, void * data);
bool LASpoint_set_attribute(void *self, unsigned int index, const void * data);
const void * LASpoint_get_attribute_name(void *self, unsigned int index);
double LASpoint_get_attribute_as_float(void *self, unsigned int index);
void LASpoint_set_attribute_as_float(void *self, unsigned int index, double value);
void LASpoint_set_attribute_1(void *self, int start, unsigned char data);
void LASpoint_set_attribute_2(void *self, int start, char data);
void LASpoint_set_attribute_3(void *self, int start, unsigned short data);
void LASpoint_set_attribute_4(void *self, int start, short data);
void LASpoint_set_attribute_5(void *self, int start, unsigned int data);
void LASpoint_set_attribute_6(void *self, int start, int data);
void LASpoint_set_attribute_7(void *self, int start, unsigned long long data);
void LASpoint_set_attribute_8(void *self, int start, long long data);
void LASpoint_set_attribute_9(void *self, int start, float data);
void LASpoint_set_attribute_10(void *self, int start, double data);
void LASpoint_destroy(void *self);


// LASvlr
unsigned short *LASvlr_field_reserved(void *self);
void *LASvlr_field_user_id(void *self);
unsigned short *LASvlr_field_record_id(void *self);
unsigned short *LASvlr_field_record_length_after_header(void *self);
void *LASvlr_field_description(void *self);
void *LASvlr_field_data(void *self);
void *LASvlr_create();


// LASevlr
unsigned short *LASevlr_field_reserved(void *self);
void *LASevlr_field_user_id(void *self);
unsigned short *LASevlr_field_record_id(void *self);
long long *LASevlr_field_record_length_after_header(void *self);
void *LASevlr_field_description(void *self);
void *LASevlr_field_data(void *self);
void *LASevlr_create();


// LASvlr_geo_keys
unsigned short *LASvlr_geo_keys_field_key_directory_version(void *self);
unsigned short *LASvlr_geo_keys_field_key_revision(void *self);
unsigned short *LASvlr_geo_keys_field_minor_revision(void *self);
unsigned short *LASvlr_geo_keys_field_number_of_keys(void *self);


// LASvlr_key_entry
unsigned short *LASvlr_key_entry_field_key_id(void *self);
unsigned short *LASvlr_key_entry_field_tiff_tag_location(void *self);
unsigned short *LASvlr_key_entry_field_count(void *self);
unsigned short *LASvlr_key_entry_field_value_offset(void *self);


// LASvlr_classification
unsigned char *LASvlr_classification_field_class_number(void *self);
void *LASvlr_classification_field_description(void *self);


// LASvlr_wave_packet_descr
void *LASvlr_wave_packet_descr_create();
void LASvlr_wave_packet_descr_clean(void *self);
unsigned char LASvlr_wave_packet_descr_getBitsPerSample(void *self);
unsigned char LASvlr_wave_packet_descr_getCompressionType(void *self);
unsigned int LASvlr_wave_packet_descr_getNumberOfSamples(void *self);
unsigned int LASvlr_wave_packet_descr_getTemporalSpacing(void *self);
double LASvlr_wave_packet_descr_getDigitizerGain(void *self);
double LASvlr_wave_packet_descr_getDigitizerOffset(void *self);
void LASvlr_wave_packet_descr_setBitsPerSample(void *self, unsigned char bps);
void LASvlr_wave_packet_descr_setCompressionType(void *self, unsigned char compression);
void LASvlr_wave_packet_descr_setNumberOfSamples(void *self, unsigned int samples);
void LASvlr_wave_packet_descr_setTemporalSpacing(void *self, unsigned int spacing);
void LASvlr_wave_packet_descr_setDigitizerGain(void *self, double gain);
void LASvlr_wave_packet_descr_setDigitizerOffset(void *self, double offset);


// LASheader
void *LASheader_field_file_signature(void *self);
unsigned short *LASheader_field_file_source_ID(void *self);
unsigned short *LASheader_field_global_encoding(void *self);
unsigned int *LASheader_field_project_ID_GUID_data_1(void *self);
unsigned short *LASheader_field_project_ID_GUID_data_2(void *self);
unsigned short *LASheader_field_project_ID_GUID_data_3(void *self);
void *LASheader_field_project_ID_GUID_data_4(void *self);
unsigned char *LASheader_field_version_major(void *self);
unsigned char *LASheader_field_version_minor(void *self);
void *LASheader_field_system_identifier(void *self);
void *LASheader_field_generating_software(void *self);
unsigned short *LASheader_field_file_creation_day(void *self);
unsigned short *LASheader_field_file_creation_year(void *self);
unsigned short *LASheader_field_header_size(void *self);
unsigned int *LASheader_field_offset_to_point_data(void *self);
unsigned int *LASheader_field_number_of_variable_length_records(void *self);
unsigned char *LASheader_field_point_data_format(void *self);
unsigned short *LASheader_field_point_data_record_length(void *self);
unsigned int *LASheader_field_number_of_point_records(void *self);
void *LASheader_field_number_of_points_by_return(void *self);
double *LASheader_field_max_x(void *self);
double *LASheader_field_min_x(void *self);
double *LASheader_field_max_y(void *self);
double *LASheader_field_min_y(void *self);
double *LASheader_field_max_z(void *self);
double *LASheader_field_min_z(void *self);
unsigned long long *LASheader_field_start_of_waveform_data_packet_record(void *self);
unsigned long long *LASheader_field_start_of_first_extended_variable_length_record(void *self);
unsigned int *LASheader_field_number_of_extended_variable_length_records(void *self);
unsigned long long *LASheader_field_extended_number_of_point_records(void *self);
void *LASheader_field_extended_number_of_points_by_return(void *self);
unsigned int *LASheader_field_user_data_in_header_size(void *self);
void *LASheader_field_user_data_in_header(void *self);
void *LASheader_field_vlrs(void *self);
void *LASheader_field_evlrs(void *self);
void *LASheader_field_vlr_geo_keys(void *self);
void *LASheader_field_vlr_geo_key_entries(void *self);
void *LASheader_field_vlr_geo_double_params(void *self);
void *LASheader_field_vlr_geo_ascii_params(void *self);
void *LASheader_field_vlr_geo_ogc_wkt_math(void *self);
void *LASheader_field_vlr_geo_ogc_wkt(void *self);
void *LASheader_field_vlr_classification(void *self);
void *LASheader_field_vlr_wave_packet_descr(void *self);
void *LASheader_field_laszip(void *self);
void *LASheader_field_vlr_lastiling(void *self);
void *LASheader_field_vlr_lasoriginal(void *self);
unsigned int *LASheader_field_user_data_after_header_size(void *self);
void *LASheader_field_user_data_after_header(void *self);
void *LASheader_create();
void LASheader_set_bounding_box(void *self, double min_x, double min_y, double min_z, double max_x, double max_y, double max_z, bool auto_scale, bool auto_offset);
void LASheader_set_global_encoding_bit(void *self, int bit);
void LASheader_unset_global_encoding_bit(void *self, int bit);
bool LASheader_get_global_encoding_bit(void *self, int bit);
void LASheader_clean_las_header(void *self);
void LASheader_clean_user_data_in_header(void *self);
void LASheader_clean_vlrs(void *self);
void LASheader_clean_evlrs(void *self);
void LASheader_clean_laszip(void *self);
void LASheader_clean_lastiling(void *self);
void LASheader_clean_lasoriginal(void *self);
void LASheader_clean_user_data_after_header(void *self);
void LASheader_clean(void *self);
void LASheader_unlink(void *self);
bool LASheader_check(void *self);
bool LASheader_is_compressed(void *self);
bool LASheader_is_lonlat(void *self, const float extend);
bool LASheader_add_vlr(void *self, const void * user_id, const unsigned short record_id, const unsigned short record_length_after_header, void * data, const bool keep_description, const void * description, const bool keep_existing);
const void * LASheader_get_vlr(void *self, const void * user_id, unsigned short record_id);
bool LASheader_remove_vlr(void *self, unsigned int i, bool delete_data);
bool LASheader_remove_vlr_1(void *self, const void * user_id, unsigned short record_id);
void LASheader_add_evlr(void *self, const void * user_id, const unsigned short record_id, const long long record_length_after_header, void * data, const bool keep_description, const void * description, const bool keep_existing);
bool LASheader_remove_evlr(void *self, unsigned int i, bool delete_data);
bool LASheader_remove_evlr_1(void *self, const void * user_id, unsigned short record_id);
void LASheader_set_lastiling(void *self, unsigned int level, unsigned int level_index, unsigned int implicit_levels, bool buffer, bool reversible, float min_x, float max_x, float min_y, float max_y);
void LASheader_set_lasoriginal(void *self);
bool LASheader_restore_lasoriginal(void *self);
bool LASheader_set_geo_keys(void *self, const int number_of_keys, const void * geo_keys);
bool LASheader_set_geo_double_params(void *self, const int num_geo_double_params, const void * geo_double_params);
void LASheader_del_geo_double_params(void *self);
bool LASheader_set_geo_ascii_params(void *self, const int num_geo_ascii_params, const void * geo_ascii_params);
void LASheader_del_geo_ascii_params(void *self);
void LASheader_set_geo_wkt_ogc_math(void *self, const int num_geo_wkt_ogc_math, const void * geo_wkt_ogc_math);
void LASheader_del_geo_wkt_ogc_math(void *self);
void LASheader_set_geo_ogc_wkt(void *self, const int num_geo_ogc_wkt, const void * geo_ogc_wkt, bool in_evlr);
void LASheader_del_geo_ogc_wkt(void *self);
bool LASheader_update_extra_bytes_vlr(void *self, const bool keep_description);
void LASheader_destroy(void *self);


// LASignore
void LASignore_usage(void *self);
void LASignore_ignore_class(void *self, unsigned char classification);
void LASignore_dont_ignore_class(void *self, unsigned char classification);
int LASignore_unparse(void *self, void * string);
bool LASignore_parse_1(void *self, unsigned int curr_parameter, const unsigned int num_parameters, const void * parameters);
unsigned int LASignore_get_decompress_selective(void *self);
bool LASignore_ignore(void *self, const void * point);
void *LASignore_create();
void LASignore_destroy(void *self);


// LASreader
void *LASreader_field_header(void *self);
void *LASreader_field_point(void *self);
long long *LASreader_field_npoints(void *self);
long long *LASreader_field_p_count(void *self);
bool LASreader_has_layers(void *self);
void LASreader_set_index(void *self, void * index);
void * LASreader_get_index(void *self);
void LASreader_set_filter(void *self, void * filter);
void * LASreader_get_filter(void *self);
void LASreader_set_transform(void *self, void * transform);
void * LASreader_get_transform(void *self);
void LASreader_set_ignore(void *self, void * ignore);
void * LASreader_get_ignore(void *self);
unsigned int LASreader_get_inside(void *self);
bool LASreader_inside_none(void *self);
bool LASreader_inside_tile(void *self, const float ll_x, const float ll_y, const float size);
float LASreader_get_t_ll_x(void *self);
float LASreader_get_t_ll_y(void *self);
float LASreader_get_t_size(void *self);
bool LASreader_inside_circle(void *self, const double center_x, const double center_y, const double radius);
double LASreader_get_c_center_x(void *self);
double LASreader_get_c_center_y(void *self);
double LASreader_get_c_radius(void *self);
bool LASreader_inside_rectangle(void *self, const double min_x, const double min_y, const double max_x, const double max_y);
double LASreader_get_r_min_x(void *self);
double LASreader_get_r_min_y(void *self);
double LASreader_get_r_max_x(void *self);
double LASreader_get_r_max_y(void *self);
bool LASreader_read_point(void *self);
bool LASreader_ignore_point(void *self);
void LASreader_compute_coordinates(void *self);
double LASreader_get_min_x(void *self);
double LASreader_get_min_y(void *self);
double LASreader_get_min_z(void *self);
double LASreader_get_max_x(void *self);
double LASreader_get_max_y(void *self);
double LASreader_get_max_z(void *self);
double LASreader_get_x(void *self);
double LASreader_get_y(void *self);
double LASreader_get_z(void *self);
double LASreader_get_x_1(void *self, const int x);
double LASreader_get_y_1(void *self, const int y);
double LASreader_get_z_1(void *self, const int z);
long long LASreader_get_X(void *self, const double x);
long long LASreader_get_Y(void *self, const double y);
long long LASreader_get_Z(void *self, const double z);
void LASreader_destroy(void *self);
void LASreader_dealloc(void *self);


// LASwaveform13reader
unsigned int *LASwaveform13reader_field_nbits(void *self);
unsigned int *LASwaveform13reader_field_nsamples(void *self);
unsigned int *LASwaveform13reader_field_temporal(void *self);
float *LASwaveform13reader_field_location(void *self);
void *LASwaveform13reader_field_XYZt(void *self);
void *LASwaveform13reader_field_XYZreturn(void *self);
void *LASwaveform13reader_field_XYZsample(void *self);
unsigned int *LASwaveform13reader_field_s_count(void *self);
unsigned int *LASwaveform13reader_field_sample(void *self);
unsigned int *LASwaveform13reader_field_sampleMin(void *self);
unsigned int *LASwaveform13reader_field_sampleMax(void *self);
void *LASwaveform13reader_field_samples(void *self);
bool LASwaveform13reader_open(void *self, const void * file_name, long long start_of_waveform_data_packet_record, const void * wave_packet_descr);
bool LASwaveform13reader_is_compressed(void *self);
bool LASwaveform13reader_read_waveform(void *self, const void * point);
bool LASwaveform13reader_get_samples(void *self);
bool LASwaveform13reader_has_samples(void *self);
bool LASwaveform13reader_get_samples_xyz(void *self);
bool LASwaveform13reader_has_samples_xyz(void *self);
void LASwaveform13reader_close(void *self);
void *LASwaveform13reader_create();
void LASwaveform13reader_destroy(void *self);


// LASreadOpener
void LASreadOpener_set_io_ibuffer_size(void *self, const unsigned int buffer_size);
unsigned int LASreadOpener_get_io_ibuffer_size(void *self);
unsigned int LASreadOpener_get_file_name_number(void *self);
unsigned int LASreadOpener_get_file_name_current(void *self);
const void * LASreadOpener_get_file_name(void *self);
const void * LASreadOpener_get_file_name_only(void *self);
const void * LASreadOpener_get_file_extension_only(void *self);
const void * LASreadOpener_get_file_name_1(void *self, unsigned int number);
const void * LASreadOpener_get_file_name_only_1(void *self, unsigned int number);
const void * LASreadOpener_get_file_extension_only_1(void *self, unsigned int number);
void * LASreadOpener_get_file_name_base(void *self);
void * LASreadOpener_get_file_name_base_1(void *self, unsigned int number);
void LASreadOpener_set_file_name(void *self, const void * file_name, bool unique);
bool LASreadOpener_add_file_name(void *self, const void * file_name, bool unique);
bool LASreadOpener_add_list_of_files(void *self, const void * list_of_files, bool unique);
void LASreadOpener_delete_file_name(void *self, unsigned int file_name_id);
bool LASreadOpener_set_file_name_current(void *self, unsigned int file_name_id);
int LASreadOpener_get_file_format(void *self, unsigned int number);
void LASreadOpener_set_merged(void *self, const bool merged);
bool LASreadOpener_is_merged(void *self);
void LASreadOpener_set_stored(void *self, const bool stored);
bool LASreadOpener_is_stored(void *self);
void LASreadOpener_set_buffer_size(void *self, const float buffer_size);
float LASreadOpener_get_buffer_size(void *self);
void LASreadOpener_set_neighbor_file_name(void *self, const void * neighbor_file_name, bool unique);
bool LASreadOpener_add_neighbor_file_name(void *self, const void * neighbor_file_name, bool unique);
bool LASreadOpener_add_neighbor_file_name_1(void *self, const void * file_name, long long npoints, double min_x, double min_y, double max_x, double max_y, bool unique);
bool LASreadOpener_add_neighbor_list_of_files(void *self, const void * list_of_files, bool unique);
void LASreadOpener_set_auto_reoffset(void *self, const bool auto_reoffset);
bool LASreadOpener_is_auto_reoffset(void *self);
void LASreadOpener_set_files_are_flightlines(void *self, const int files_are_flightlines);
int LASreadOpener_are_files_flightlines(void *self);
void LASreadOpener_set_files_are_flightlines_index(void *self, const int files_are_flightlines_index);
int LASreadOpener_get_files_flight_index(void *self);
void LASreadOpener_set_apply_file_source_ID(void *self, const bool apply_file_source_ID);
bool LASreadOpener_applying_file_source_ID(void *self);
void LASreadOpener_set_scale_factor(void *self, const void * scale_factor);
const void * LASreadOpener_get_scale_factor(void *self);
void LASreadOpener_set_offset(void *self, const void * offset);
const void * LASreadOpener_get_offset(void *self);
void LASreadOpener_set_translate_intensity(void *self, const float translation);
void LASreadOpener_set_scale_intensity(void *self, const float scale);
void LASreadOpener_set_translate_scan_angle(void *self, const float translate_scan_angle);
void LASreadOpener_set_scale_scan_angle(void *self, const float scale_scan_angle);
void LASreadOpener_add_attribute(void *self, int data_type, const void * name, const void * description, double scale, double offset, double pre_scale, double pre_offset, double no_data);
bool LASreadOpener_set_point_type(void *self, unsigned char point_type);
void LASreadOpener_set_parse_string(void *self, const void * parse_string);
void LASreadOpener_set_skip_lines(void *self, const unsigned int number_of_lines);
void LASreadOpener_set_populate_header(void *self, bool populate_header);
void LASreadOpener_set_keep_lastiling(void *self, bool keep_lastiling);
void LASreadOpener_set_pipe_on(void *self, bool pipe_on);
const void * LASreadOpener_get_parse_string(void *self);
void LASreadOpener_usage(void *self);
void LASreadOpener_set_decompress_selective(void *self, unsigned int decompress_selective);
void LASreadOpener_set_inside_tile(void *self, const float ll_x, const float ll_y, const float size);
void LASreadOpener_set_inside_circle(void *self, const double center_x, const double center_y, const double radius);
void LASreadOpener_set_inside_rectangle(void *self, const double min_x, const double min_y, const double max_x, const double max_y);
bool LASreadOpener_parse(void *self, int argc, void * argv, bool parse_ignore);
bool LASreadOpener_is_piped(void *self);
bool LASreadOpener_is_buffered(void *self);
bool LASreadOpener_is_header_populated(void *self);
bool LASreadOpener_active(void *self);
bool LASreadOpener_is_inside(void *self);
int LASreadOpener_unparse(void *self, void * string);
void LASreadOpener_set_filter(void *self, void * filter);
void * LASreadOpener_get_filter(void *self);
void LASreadOpener_set_transform(void *self, void * transform);
void * LASreadOpener_get_transform(void *self);
void LASreadOpener_set_ignore(void *self, void * ignore);
void * LASreadOpener_get_ignore(void *self);
void LASreadOpener_reset(void *self);
const void * LASreadOpener_get_temp_file_base(void *self);
void * LASreadOpener_open(void *self, const void * other_file_name, bool reset_after_other);
bool LASreadOpener_reopen(void *self, void * lasreader, bool remain_buffered);
void * LASreadOpener_open_waveform13(void *self, const void * lasheader);
int LASreadOpener_get_number_attributes(void *self);
int LASreadOpener_get_attribute_data_type(void *self, unsigned int index);
const void * LASreadOpener_get_attribute_name(void *self, unsigned int index);
const void * LASreadOpener_get_attribute_description(void *self, unsigned int index);
double LASreadOpener_get_attribute_scale(void *self, unsigned int index);
double LASreadOpener_get_attribute_offset(void *self, unsigned int index);
double LASreadOpener_get_attribute_no_data(void *self, unsigned int index);
void *LASreadOpener_create();
void LASreadOpener_destroy(void *self);


// LASreaderLAS
void LASreaderLAS_set_delete_stream(void *self, bool delete_stream);
bool LASreaderLAS_open(void *self, const void * file_name, int io_buffer_size, bool peek_only, unsigned int decompress_selective);
bool LASreaderLAS_open_1(void *self, void * file, bool peek_only, unsigned int decompress_selective);
bool LASreaderLAS_open_3(void *self, void * stream, bool peek_only, unsigned int decompress_selective);
int LASreaderLAS_get_format(void *self);
bool LASreaderLAS_seek(void *self, const long long p_index);
void * LASreaderLAS_get_stream(void *self);
void LASreaderLAS_close(void *self, bool close_stream);
void *LASreaderLAS_create();
void LASreaderLAS_destroy(void *self);


// LASreaderLASrescale
void *LASreaderLASrescale_create(double x_scale_factor, double y_scale_factor, double z_scale_factor, bool check_for_overflow);


// LASreaderLASreoffset
void *LASreaderLASreoffset_create(double x_offset, double y_offset, double z_offset);
void *LASreaderLASreoffset_create_1();


// LASreaderLASrescalereoffset
void *LASreaderLASrescalereoffset_create(double x_scale_factor, double y_scale_factor, double z_scale_factor, double x_offset, double y_offset, double z_offset);
void *LASreaderLASrescalereoffset_create_1(double x_scale_factor, double y_scale_factor, double z_scale_factor);
#ifdef __cplusplus
}
#endif
#endif /* CWRAPPER_H_ */

