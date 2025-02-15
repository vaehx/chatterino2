#pragma once

#include "messages/Emote.hpp"
#include "widgets/listview/GenericListItem.hpp"

#include <functional>

namespace chatterino {

class InputCompletionItem : public GenericListItem
{
    using ActionCallback = std::function<void(const QString &)>;

public:
    InputCompletionItem(const EmotePtr &emote, const QString &text,
                        ActionCallback action);

    // GenericListItem interface
public:
    virtual void action() override;
    virtual void paint(QPainter *painter, const QRect &rect) const override;
    virtual QSize sizeHint(const QRect &rect) const override;

private:
    EmotePtr emote_;
    QString text_;
    ActionCallback action_;
};

}  // namespace chatterino
