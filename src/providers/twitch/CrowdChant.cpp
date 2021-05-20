#include "CrowdChant.hpp"
#include "common/QLogging.hpp"
#include "util/RapidjsonHelpers.hpp"

namespace chatterino {

CrowdChant::CrowdChant(rapidjson::Value &chant)
{
    rapidjson::Value user;
    if (!(this->hasParsedSuccessfully =
              rj::getSafeObject(chant, "user", user)))
    {
        qCDebug(chatterinoTwitch) << "No user info found for chant";
        return;
    }

    if (!(this->hasParsedSuccessfully = rj::getSafe(user, "id", this->user.id)))
    {
        qCDebug(chatterinoTwitch) << "No id found for user in chant";
        return;
    }

    if (!(this->hasParsedSuccessfully =
              rj::getSafe(user, "login", this->user.login)))
    {
        qCDebug(chatterinoTwitch) << "No login name found for user in chant";
        return;
    }

    if (!(this->hasParsedSuccessfully =
              rj::getSafe(user, "display_name", this->user.displayName)))
    {
        qCDebug(chatterinoTwitch) << "No display name found for user in chant";
        return;
    }


    if (!(this->hasParsedSuccessfully =
              rj::getSafe(chant, "channel_id", this->channelId)))
    {
        qCDebug(chatterinoTwitch) << "No channel_id found for chant";
        return;
    }

    if (!(this->hasParsedSuccessfully =
              rj::getSafe(chant, "chat_message_id", this->chatMessageId)))
    {
        qCDebug(chatterinoTwitch) << "No chat_message_id found for chant";
        return;
    }

    if (!(this->hasParsedSuccessfully = rj::getSafe(chant, "text", this->text)))
    {
        qCDebug(chatterinoTwitch) << "No text found for chant";
        return;
    }

    if (!(this->hasParsedSuccessfully =
              rj::getSafe(chant, "created_at", this->createdAt)))
    {
        qCDebug(chatterinoTwitch) << "No created_at found for chant";
        return;
    }

    if (!(this->hasParsedSuccessfully =
              rj::getSafe(chant, "ends_at", this->endsAt)))
    {
        qCDebug(chatterinoTwitch) << "No ends_at found for chant";
        return;
    }
}

}
