//
// Created by noreasonexception on 4/3/18.
//

#include "StreamPanel.h"

StreamPanel::StreamPanel() {


}

bool StreamPanel::initializeDataView()try {
    dataView=onGenerateDataView();
    return true;
}catch (std::exception&e){return false;}

QListView *StreamPanel::onGenerateDataView() {
    return new QListView();
}

bool StreamPanel::generic_initializer(){
    return AlanPanel::generic_initializer()&&
           initializeDataView();

}
