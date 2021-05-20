#pragma once

#include "common/Aliases.hpp"

#include <rapidjson/document.h>

namespace chatterino {

struct CrowdChant {
    CrowdChant(rapidjson::Value &chant);
    CrowdChant() = delete;
    QString id;
    QString channelId;
    QString chatMessageId;
    QString text;
    QString createdAt; // iso 8601
    QString endsAt; // iso 8601

    bool hasParsedSuccessfully;

    struct {
        QString id;
        QString login;
        QString displayName;
    } user; // the user who started the chant

private:
    void parseUser(rapidjson::Value &user);
};

}  // namespace chatterino
