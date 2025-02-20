// main.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <memory> 
#ifdef _WIN32
    #include <sys/io.h>    
#else
        #include <sys/uio.h>
#endif

// #include <io.h> 
#include <boost/thread.hpp>
 
#include <fcntl.h>
//#include <boost/thread/mutex.hpp>



// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
