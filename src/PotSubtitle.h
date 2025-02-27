﻿#pragma once
#include "PotBase.h"

extern "C"
{
#include "ass/ass.h"
#include "ass/ass_types.h"
}

#include <set>
#include <vector>

enum PotPSubtitleType
{
    BPSUB_TYPE_ASS,
    BPSUB_TYPE_SRT
};

class PotSubtitle : public PotBase
{
public:
    PotSubtitle();
    virtual ~PotSubtitle();

protected:
    PotPSubtitleType type_;
    std::string subfilename_, fontpath_;
    bool exist_ = false;
    std::set<std::string> contents_;

public:
    bool exist() { return exist_; }

    virtual void init() {}
    virtual bool openSubtitle(const std::string& filename) { return false; }
    virtual void closeSubtitle() {}
    virtual int show(int time) { return 1; }
    virtual void destroy() {}
    virtual void setFrameSize(int w, int h) {}
    virtual void openSubtitleFromMem(const std::string& str) {}
    virtual void readOne(const std::string& str, int start_time, int end_time) {}
    virtual void clear() {}
};
