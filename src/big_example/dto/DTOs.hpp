#ifndef DTOs_hpp
#define DTOs_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  Data Transfer Object. Object containing fields only.
 *  Used in API for serialization/deserialization and validation
 */
class MyDto : public oatpp::DTO {
  
  DTO_INIT(MyDto, DTO)
  

  DTO_FIELD_INFO(message) {
    info->description = "this is our main demo data!"; 
    info->required = true; // mark field as required
  }
  DTO_FIELD(String, message);
  
};

#include OATPP_CODEGEN_END(DTO)

#endif /* DTOs_hpp */
