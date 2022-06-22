#ifndef MyController_hpp
#define MyController_hpp

#include "big_example/dto/DTOs.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- Begin Codegen

/**
 * Sample Api Controller.
 */
class MyController : public oatpp::web::server::api::ApiController {
  MyDto::Wrapper data = MyDto::createShared();

public:
  /**
   * Constructor with object mapper.
   * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
   */
  MyController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper)
  {
    data->message = "Hello World!";
  }

public:

  ENDPOINT_INFO(getData) {
    info->summary = "Retrieve the 'data'";
    info->addTag("demo");
    info->addResponse<Object<MyDto>>(Status::CODE_200, "application/json");
  }  
  ENDPOINT("GET", "/data", getData) {
    return createDtoResponse(Status::CODE_200, data);
  }
  
  ENDPOINT_INFO(updateData) {
    info->summary = "Update the 'data'";
    info->addTag("demo");
    info->addConsumes<Object<MyDto>>("application/json");
    info->addResponse(Status::CODE_200);
  }  
  ENDPOINT("PUT", "/data", updateData, BODY_DTO(Object<MyDto>, new_data)) {
    for (auto p: new_data.getPropertiesList()) {
      if (p->info.required) {
        std::string error_text = std::string(p->name)+" required"; 
        auto value = p->getAsRef(new_data.get());
        OATPP_ASSERT_HTTP(value.get()!=nullptr, Status::CODE_400, error_text)
      }
    }
    data->message = new_data->message;
    return createResponse(Status::CODE_200);
  }
  
};

#include OATPP_CODEGEN_END(ApiController) //<-- End Codegen

#endif /* MyController_hpp */
