#ifndef TYPES_H
#define TYPES_H

#include <string>

typedef std::string string_type;
typedef string_type::value_type char_type;

/** \brief Enumerator for indicating relative or absolute paths.
*/
enum EPathBase
{
    pbABSOLUTE,     ///< Absolute path
    pbRELATIVE      ///< Path relative to the application directory
};



#endif // TYPES_H
