/* Copyright (c) 2013 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */
#ifndef BLE_GATTS_CONN_H__
#define BLE_GATTS_CONN_H__

/**
 * @addtogroup ser_codecs Serialization codecs
 * @ingroup ble_sdk_lib_serialization
 */

/**
 * @addtogroup ser_conn_s110_codecs Connectivity s110 codecs
 * @ingroup ser_codecs
 */

/**@file
 *
 * @defgroup ble_gatts_conn GATTS Connectivity command request decoders and command response encoders
 * @{
 * @ingroup  ser_conn_s110_codecs
 *
 * @brief    GATTS Connectivity command request decoders and command response encoders
 */

#include "ble_gatts.h"
#include "ble.h"

uint32_t ble_gatts_value_get_req_dec(uint8_t const * const p_buf,
                                     uint16_t              packet_len,
                                     uint16_t * const      handle,
                                     uint16_t * const      offset,
                                     uint16_t * * const    pp_len,
                                     uint8_t * * const     pp_data);

uint32_t ble_gatts_value_get_rsp_enc(uint32_t         return_code,
                                     uint8_t * const  p_buf,
                                     uint32_t * const p_buf_len,
                                     uint8_t * const  p_value,
                                     uint16_t * const p_value_len);

/**@brief Decodes @ref ble_gatts_characteristic_add command request.
 *
 * @sa @ref nrf51_sd_ble_gatts_characteristic_add for packet format,
 *     @ref ble_gatts_characteristic_add_rsp_enc for response encoding.
 *
 * @param[in] p_buf               Pointer to beginning of command request packet.
 * @param[in] buf_len             Length (in bytes) of request packet.
 * @param[out] p_service_handle   Pointer to the service_handle.
 * @param[out] pp_char_md         Pointer to pointer to the location where Characteristic metadata
 *                                will be decoded.
 * @param[out] pp_attr_char_value Pointer to pointer to the location where GATT Attribute will be
 *                                decoded.
 * @param[out] pp_handles         Pointer to pointer to the location where Characteristic definition
 *                                handles will be decoded.
 *
 * @retval NRF_SUCCESS                Decoding success.
 * @retval NRF_ERROR_NULL             Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Decoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_characteristic_add_req_dec(uint8_t const * const              p_buf,
                                              uint32_t                           buf_len,
                                              uint16_t *                         p_service_handle,
                                              ble_gatts_char_md_t * *            constpp_char_md,
                                              ble_gatts_attr_t * * const         pp_attr_char_value,
                                              ble_gatts_char_handles_t * * const pp_handles);

/**@brief Encodes @ref ble_gatts_sys_attr_get_rsp_enc command response.
 *
 * @sa @ref sd_ble_gatts_sys_attr_get for packet format.
 *     @ref ble_gatts_sys_attr_get_req_dec for request decoding.
 *
 * @param[in] return_code         Return code indicating if command was successful or not.
 * @param[out] p_buf              Pointer to buffer where encoded data command response will be
 *                                returned.
 * @param[in,out] p_buf_len       \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command response packet.
 * @param[in] p_handles           Pointer to handle struct to be encoded.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_characteristic_add_rsp_enc(uint32_t                               return_code,
                                              uint8_t * const                        p_buf,
                                              uint32_t * const                       p_buf_len,
                                              ble_gatts_char_handles_t const * const p_handles);

/**@brief Decodes @ref ble_gatts_include_add command request.
 *
 * @sa @ref nrf51_sd_ble_gatts_include_add for packet format,
 *     @ref ble_gatts_include_add_rsp_enc for response encoding.
 *
 * @param[in] p_buf               Pointer to beginning of command request packet.
 * @param[in] buf_len             Length (in bytes) of request packet.
 * @param[out] p_service_handle   Pointer to the service_handle.
 * @param[out] p_inc_srvc_handle  Pointer to the handle of the included service.
 * @param[out] pp_include_handle  Pointer to Pointer to 16-bit word where the assigned handle will be stored.
 *
 * @retval NRF_SUCCESS                Decoding success.
 * @retval NRF_ERROR_NULL             Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Decoding failure. Incorrect buffer length.
 */

uint32_t ble_gatts_include_add_req_dec(uint8_t const * const p_buf,
                                       uint16_t              packet_len,
                                       uint16_t * const      p_service_handle,
                                       uint16_t * const      p_inc_srvc_handle,
                                       uint16_t * * const    pp_include_handle);

/**@brief Encodes @ref ble_gatts_include_add_rsp_enc command response.
 *
 * @sa @ref sd_ble_gatts_include_add_rsp_enc for packet format.
 *
 * @param[in] return_code         Return code indicating if command was successful or not.
 * @param[out] p_buf              Pointer to buffer where encoded data command response will be
 *                                returned.
 * @param[in,out] p_buf_len       \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command response packet.
 * @param[in] p_include_handle    Pointer to a 16-bit word where the assigned handle was stored.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */

uint32_t ble_gatts_include_add_rsp_enc(uint32_t               return_code,
                                       uint8_t * const        p_buf,
                                       uint32_t * const       p_buf_len,
                                       uint16_t const * const p_include_handle);

/**@brief Decodes @ref ble_gatts_service_add command request.
 *
 * @sa @ref nrf51_sd_ble_gatts_service_add for packet format,
 *     @ref ble_gatts_service_add_rsp_enc for response encoding.
 *
 * @param[in] p_buf               Pointer to beginning of command request packet.
 * @param[in] buf_len             Length (in bytes) of request packet.
 * @param[out] p_type             Pointer to the service type.
 * @param[out] pp_uuid            Pointer to pointer to service UUID.
 * @param[out] pp_handle          Pointer to Pointer to a 16-bit word where the assigned handle will be stored.
 *
 * @retval NRF_SUCCESS                Decoding success.
 * @retval NRF_ERROR_NULL             Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Decoding failure. Incorrect buffer length.
 */

uint32_t ble_gatts_service_add_req_dec(uint8_t const * const p_buf,
                                       uint32_t              buf_len,
                                       uint8_t * const       p_type,
                                       ble_uuid_t * * const  pp_uuid,
                                       uint16_t * * const    pp_handle);

/**@brief Encodes @ref ble_gatts_service_add_rsp_enc command response.
 *
 * @sa @ref sd_ble_gatts_service_add_rsp_enc for packet format.
 *
 * @param[in] return_code         Return code indicating if command was successful or not.
 * @param[out] p_buf              Pointer to buffer where encoded data command response will be
 *                                returned.
 * @param[in,out] p_buf_len       \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command response packet.
 * @param[in] p_handle            Pointer to a 16-bit word where the assigned handle was stored.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */

uint32_t ble_gatts_service_add_rsp_enc(uint32_t               return_code,
                                       uint8_t * const        p_buf,
                                       uint32_t * const       p_buf_len,
                                       uint16_t const * const p_handle);

/**@brief Decodes @ref ble_gatts_sys_attr_get_req_dec command request.
 *
 * @sa @ref sd_ble_gatts_sys_attr_get for packet format,
 *     @ref ble_gatts_sys_attr_get_rsp_enc for response encoding.
 *
 * @param[in] p_buf           Pointer to beginning of command request packet.
 * @param[in] packet_len      Length (in bytes) of response packet.
 * @param[out] p_conn_handle   Pointer to connectiton handle.
 * @param[out] pp_sys_attr_data Pointer to pointer to buffer where system attributes data will be filled in.
 * @param[out] pp_sys_attr_data_len Pointer to pointer to variable which contains size of buffer for system attributes.
 *
 * @retval NRF_SUCCESS                Decoding success.
 * @retval NRF_ERROR_NULL             Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_PARAM    Decoding failure. Invalid operation type.
 */
uint32_t ble_gatts_sys_attr_get_req_dec(uint8_t const * const p_buf,
                                        uint32_t              packet_len,
                                        uint16_t * const      p_conn_handle,
                                        uint8_t * * const     pp_sys_attr_data,
                                        uint16_t * * const    pp_sys_attr_data_len);

/**@brief Encodes @ref ble_gatts_sys_attr_get_rsp_enc command response.
 *
 * @sa @ref sd_ble_gatts_sys_attr_get for packet format.
 *     @ref ble_gatts_sys_attr_get_req_dec for request decoding.
 *
 * @param[in] return_code         Return code indicating if command was successful or not.
 * @param[out] p_buf              Pointer to buffer where encoded data command response will be
 *                                returned.
 * @param[in,out] p_buf_len       \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command response packet.
 * @param[in] p_sys_attr_data     Pointer to buffer where system attributes data are storred.
 * @param[in] p_sys_attr_data_len Pointer to variable which contains size of buffer for system attributes.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_sys_attr_get_rsp_enc(uint32_t               return_code,
                                        uint8_t * const        p_buf,
                                        uint32_t * const       p_buf_len,
                                        uint8_t const * const  p_sys_attr_data,
                                        uint16_t const * const p_sys_attr_data_len);

/**@brief Decodes @ref ble_gatts_value_set command request.
 *
 * @sa @ref nrf51_sd_ble_gatts_value_set for packet format,
 *     @ref ble_gatts_value_set_rsp_enc for response encoding.
 *
 * @param[in] p_buf           Pointer to beginning of command request packet.
 * @param[in] packet_len      Length (in bytes) of response packet.
 * @param[out] p_handle       Pointer to attribute handle
 * @param[out] p_offset       Pointer to offset
 * @param[out] pp_value_len   Pointer to pointer to attribute length
 * @param[out] pp_value       Pointer to pointer to attribute value
 *
 * @retval NRF_SUCCESS                Decoding success.
 * @retval NRF_ERROR_NULL             Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_PARAM    Decoding failure. Invalid operation type.
 */

uint32_t ble_gatts_value_set_req_dec(uint8_t const * const p_buf,
                                     uint16_t              packet_len,
                                     uint16_t *            p_handle,
                                     uint16_t *            p_offset,
                                     uint16_t * * const    pp_value_len,
                                     uint8_t * * const     pp_value);

/**@brief Encodes @ref ble_gatts_value_set command response.
 *
 * @sa @ref nrf51_sd_ble_gatts_value_set for packet format.
 *
 * @param[in]      return_code    Return code indicating if command was successful or not.
 * @param[in]      p_buf          Pointer to buffer where encoded data command response will be
 *                                returned.
 * @param[in, out] p_buf_len      \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command response packet.
 * @param[in]      value_len      \c in: size of value returned when value was written with success
 *

 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_value_set_rsp_enc(uint32_t         return_code,
                                     uint8_t * const  p_buff,
                                     uint32_t * const p_buff_len,
                                     uint16_t         value_len);



/**@brief Decodes @ref ble_gatts_sys_attr_set command request.
 *
 * @sa @ref nrf51_sd_ble_gatts_sys_attr_set for packet format,
 *     @ref ble_gatts_sys_attr_set_rsp_enc for response encoding.
 *
 * @param[in] p_buf                Pointer to beginning of command request packet.
 * @param[in] packet_len           Length (in bytes) of request packet.
 * @param[out] p_conn_handle       Pointer to the buffer raw data to be placed in advertisement packet.
 * @param[out] pp_sys_attr_data    Pointer to pointer to system attribute data.
 * @param[out] p_sys_attr_data_len Pointer to data length for system attribute data.
 *
 * @retval NRF_SUCCESS                Decoding success.
 * @retval NRF_ERROR_NULL             Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Decoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_sys_attr_set_req_dec(uint8_t const * const p_buf,
                                        uint32_t              packet_len,
                                        uint16_t * const      p_conn_handle,
                                        uint8_t * * const     pp_sys_attr_data,
                                        uint16_t * const      p_sys_attr_data_len);

/**@brief Encodes @ref ble_gatts_sys_attr_set command response.
 *
 * @sa @ref nrf51_sd_ble_gatts_sys_attr_set for packet format.
 *     @ref ble_gatts_sys_attr_set_req_dec for request decoding.
 *
 * @param[in] return_code         Return code indicating if command was successful or not.
 * @param[out] p_buf              Pointer to buffer where encoded data command response will be
 *                                returned.
 * @param[in,out] p_buf_len       \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command response packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_sys_attr_set_rsp_enc(uint32_t         return_code,
                                        uint8_t * const  p_buf,
                                        uint32_t * const p_buf_len);

/**@brief Decodes @ref ble_gatts_hvx_req_dec command request.
 *
 * @sa @ref sd_ble_gatts_hvx for packet format,
 *     @ref ble_gatts_hvx_rsp_enc for response encoding.
 *
 * @param[in] p_buf                Pointer to beginning of command request packet.
 * @param[in] packet_len           Length (in bytes) of request packet.
 * @param[out] p_conn_handle       Pointer to the buffer raw data to be placed in advertisement packet.
 * @param[out] pp_hvx_params       Pointer to an HVx parameters structure.
 *
 * @retval NRF_SUCCESS                Decoding success.
 * @retval NRF_ERROR_NULL             Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Decoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_hvx_req_dec(uint8_t const * const            p_buf,
                               uint32_t                         packet_len,
                               uint16_t * const                 p_conn_handle,
                               ble_gatts_hvx_params_t * * const pp_hvx_params);

/**@brief Encodes @ref ble_gatts_hvx_rsp_enc command response.
 *
 * @sa @ref sd_ble_gatts_sys_attr_set for packet format.
 *     @ref ble_gatts_hvx_req_dec for request decoding.
 *
 * @param[in] return_code         Return code indicating if command was successful or not.
 * @param[out] p_buf              Pointer to buffer where encoded data command response will be
 *                                returned.
 * @param[in,out] p_buf_len       \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command response packet.
 * @param[in] p_bytes_written     Pointer to number of bytes written.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_hvx_rsp_enc(uint32_t               return_code,
                               uint8_t * const        p_buf,
                               uint32_t * const       p_buf_len,
                               uint16_t const * const p_bytes_written);

/**@brief Decodes @ref sd_ble_gatts_descriptor_add command request.
 *
 * @sa @ref sd_ble_gatts_descriptor_add for packet format,
 *     @ref ble_gatts_descriptor_add_rsp_enc for response encoding.
 *
 * @param[in] p_buf                Pointer to beginning of command request packet.
 * @param[in] packet_len           Length (in bytes) of request packet.
 * @param[out] p_char_handle       Pointer to buffer where characteristic handle will be.
                                   returned.
 * @param[out] pp_gatts_attr_t     Pointer to pointer to an attribute structure.
 * @param[out] pp_handle           Pointer to pointer to descriptor handle.
 *
 * @retval NRF_SUCCESS                Decoding success.
 * @retval NRF_ERROR_NULL             Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Decoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_descriptor_add_req_dec(uint8_t const * const      p_buf,
                                          uint32_t                   packet_len,
                                          uint16_t * const           p_char_handle,
                                          ble_gatts_attr_t * * const pp_attr,
                                          uint16_t * * const         pp_handle);

/**@brief Encodes @ref sd_ble_gatts_descriptor_add command response.
 *
 * @sa @ref sd_ble_gatts_sys_attr_set for packet format.
 *     @ref ble_gatts_descriptor_add_req_dec for request decoding.
 *
 * @param[in] return_code         Return code indicating if command was successful or not.
 * @param[out] p_buf              Pointer to buffer where encoded data command response will be
 *                                returned.
 * @param[in,out] p_buf_len       \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command response packet.
 * @param[in] handle              Descriptor handle value.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_descriptor_add_rsp_enc(uint32_t         return_code,
                                          uint8_t * const  p_buf,
                                          uint32_t * const p_buf_len,
                                          uint16_t         handle);

/**@brief Decodes @ref ble_gatts_rw_authorize_reply command request.
 *
 * @sa @ref nrf51_sd_ble_gatts_rw_authorize_reply for packet format,
 *     @ref ble_gatts_rw_authorize_reply_rsp_enc for response encoding.
 *
 * @param[in] p_buf            Pointer to beginning of command request packet.
 * @param[in] packet_len       Length (in bytes) of response packet.
 * @param[out] p_conn_handle   Pointer to connection handle.
 * @param[out] pp_reply_params Pointer to pointer to \ref ble_gatts_rw_authorize_reply_params_t
 *
 * @retval NRF_SUCCESS                Decoding success.
 * @retval NRF_ERROR_NULL             Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_PARAM    Decoding failure. Invalid operation type.
 */

uint32_t ble_gatts_rw_authorize_reply_req_dec(
    uint8_t const * const p_buf,
    uint32_t
    packet_len,
    uint16_t *
    p_conn_handle,
    ble_gatts_rw_authorize_reply_params_t * * const
    pp_reply_params);

/**@brief Encodes @ref ble_gatts_rw_authorize_reply command response.
 *
 * @sa @ref nrf51_sd_ble_gatts_rw_authorize_reply for packet format.
 *     @ref ble_gatts_rw_authorize_reply_req_dec for request decoding.
 *
 * @param[in] return_code         Return code indicating if command was successful or not.
 * @param[out] p_buf              Pointer to buffer where encoded data command response will be
 *                                returned.
 * @param[in,out] p_buf_len       \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command response packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_rw_authorize_reply_rsp_enc(uint32_t         return_code,
                                              uint8_t * const  p_buf,
                                              uint32_t * const p_buf_len);

/**@brief Decodes @ref ble_gatts_service_changed command request.
 *
 * @sa @ref nrf51_sd_ble_gatts_service_changed for packet format,
 *     @ref ble_gatts_service_changed_rsp_enc for response encoding.
 *
 * @param[in] p_buf            Pointer to beginning of command request packet.
 * @param[in] packet_len       Length (in bytes) of response packet.
 * @param[out] p_conn_handle   Pointer to connection handle.
 * @param[out] p_start_handle  Pointer to start handle.
 * @param[out] p_end_handle    Pointer to end handle.
 *
 * @retval NRF_SUCCESS                Decoding success.
 * @retval NRF_ERROR_NULL             Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_PARAM    Decoding failure. Invalid operation type.
 */
uint32_t ble_gatts_service_changed_req_dec(uint8_t const * const p_buf,
                                           uint32_t              packet_len,
                                           uint16_t *            p_conn_handle,
                                           uint16_t *            p_start_handle,
                                           uint16_t *            p_end_handle);

/**@brief Encodes @ref ble_gatts_service_changed command response.
 *
 * @sa @ref nrf51_sd_ble_gatts_service_changed for packet format.
 *     @ref ble_gatts_service_changed_req_dec for request decoding.
 *
 * @param[in] return_code         Return code indicating if command was successful or not.
 * @param[out] p_buf              Pointer to buffer where encoded data command response will be
 *                                returned.
 * @param[in,out] p_buf_len       \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command response packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gatts_service_changed_rsp_enc(uint32_t         return_code,
                                           uint8_t * const  p_buf,
                                           uint32_t * const p_buf_len);

/** @} */
#endif //BLE_GATTS_CONN_H__

