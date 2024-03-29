#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "flv.h"
#include "sub.h"

#define PREV_SIZE_HEADER 4

UNIFEX_TERM add_caption(UnifexEnv *env, UnifexPayload *flv, char *text)
{
    // init
    flvtag_t tag;
    UnifexPayload payload;
    flvtag_init(&tag);

    // put payload data in the tag excluding the first 4 bytes
    // to respect the internal tag format
    flv_payload_read_tag(&flv->data[PREV_SIZE_HEADER], &tag);

    // check if the tag is writable
    if (flvtag_avcpackettype_nalu == flvtag_avcpackettype(&tag)) {
        flvtag_addcaption_text(&tag, text);
    } else {
        flvtag_free(&tag);
        return add_caption_result_error(env, "type_not_nalu");
    }

    // allocate and write the output payload
    size_t size = flvtag_raw_size(&tag);
    unifex_payload_alloc(env, UNIFEX_PAYLOAD_BINARY, size, &payload);
    memcpy(payload.data, flvtag_raw_data(&tag), size);

    flvtag_free(&tag);

    UNIFEX_TERM result = add_caption_result_ok(env, &payload);
    unifex_payload_release(&payload);
    return result;
}

UNIFEX_TERM clear_caption(UnifexEnv *env, UnifexPayload *flv)
{
    return add_caption(env, flv, NULL);
}


void handle_destroy_state(UnifexEnv *env)
{
    UNIFEX_UNUSED(env);
}
