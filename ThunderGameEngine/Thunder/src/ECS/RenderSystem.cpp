#include "RenderSystem.h"
const int noDimPerVertex = 7;

RenderSystem::RenderSystem(ComponentManager& componentManager, Shader& shader)
	: m_componentManager(componentManager), m_shader(shader)
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::Update()
{
    glm::mat4 projMatrix = glm::mat4(1.0f), vMatrix = glm::mat4(1.0f);
    // Get all entities with a CameraComponent
    // There should only be one camera entity
    std::vector<Entity> cameraEntities = GetComponentManager().GetAllEntitiesWithComponent<CameraComponent>();
    for (const Entity& entity : cameraEntities) {
        GetComponentManager().GetComponent<CameraComponent>(entity).UpdateProjectionMatrix();
        projMatrix = GetComponentManager().GetComponent<CameraComponent>(entity).GetProjectionMatrix();

        glm::vec3 position = GetComponentManager().GetComponent<TransformComponent>(entity).GetPosition();
        glm::quat orientation = GetComponentManager().GetComponent<TransformComponent>(entity).GetRotation();
        vMatrix = GetComponentManager().GetComponent<CameraComponent>(entity).GetViewMatrix(position, orientation);
    }
    // Get all entities with a RenderComponent3D
    std::vector<Entity> entities = GetComponentManager().GetAllEntitiesWithComponent<RenderComponent3D>();
    for (const Entity& entity : entities) {
        RenderEntity(entity, projMatrix, vMatrix);
    }
}

void RenderSystem::RenderEntity(const Entity& entity, glm::mat4 projectionMatrix, glm::mat4 viewMatrix)
{
    // Get the RenderComponent3D of the entity
    const RenderComponent3D& renderComponent = GetComponentManager().GetComponent<RenderComponent3D>(entity);

    int vertSize = renderComponent.vertices.size() * noDimPerVertex;
    float* r_vertices = new float[vertSize];
    int count = 0;
    // Set up your rendering logic here
    // For example, bind the shader, set up the vertex data and draw
    for (int i = 0; i < renderComponent.vertices.size(); i++) {
        r_vertices[count] = renderComponent.vertices[i].x;
        r_vertices[count + 1] = renderComponent.vertices[i].y;
        r_vertices[count + 2] = renderComponent.vertices[i].z;
        r_vertices[count + 3] = renderComponent.color[i].r;
        r_vertices[count + 4] = renderComponent.color[i].g;
        r_vertices[count + 5] = renderComponent.color[i].b;
        r_vertices[count + 6] = renderComponent.color[i].a;
        count += noDimPerVertex;
    }

    const GLuint* r_indices = renderComponent.indices.data();

    VertexArray vao;
    VertexBuffer vbo(r_vertices, vertSize * sizeof(float));
    ElementBuffer ebo(r_indices, renderComponent.indices.size());

    vbo.Bind();

    VertexAttribute positionAttrib(0, 3, GL_FLOAT, GL_FALSE, noDimPerVertex * sizeof(float), (void*)0);
    VertexAttribute colorAttrib(1, 4, GL_FLOAT, GL_FALSE, noDimPerVertex * sizeof(float), (void*)(3 * sizeof(float)));

    GLuint MVP_ID = glGetUniformLocation(m_shader.GetProgram(), "MVP");
    glm::mat4 MVP;
    if (GetComponentManager().HasComponent<TransformComponent>(entity))
        MVP = projectionMatrix * viewMatrix * GetComponentManager().GetComponent<TransformComponent>(entity).GetModelMatrix();
    else
        MVP = projectionMatrix * viewMatrix * glm::mat4(1.0f);
    glUniformMatrix4fv(MVP_ID, 1, GL_FALSE, &MVP[0][0]);

    m_shader.Use();
    vao.Bind();
    vao.AddAttribute(positionAttrib);
    vao.AddAttribute(colorAttrib);
    ebo.Bind();

    glDrawElements(GL_TRIANGLES, renderComponent.indices.size(), GL_UNSIGNED_INT, 0);

    // Unbind everything
    vao.Unbind();
    vbo.Unbind();
    ebo.Unbind();
}

ComponentManager& RenderSystem::GetComponentManager() const
{
	return m_componentManager;
}

Shader& RenderSystem::GetShader() const
{
	return m_shader;
}
