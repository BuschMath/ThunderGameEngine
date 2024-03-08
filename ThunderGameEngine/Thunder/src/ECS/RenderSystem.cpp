#include "RenderSystem.h"
const int noDimPerVertex = 7;

RenderSystem::RenderSystem(ComponentManager& componentManager, Shader& shader)
	: m_componentManager(componentManager), m_shader(shader)
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::RenderEntity(const Entity& entity)
{
    // Get the RenderComponent3D of the entity
    const RenderComponent3D& renderComponent = GetComponentManager().GetComponent<RenderComponent3D>(entity);

    int vertSize = renderComponent.vertices.size() * noDimPerVertex;
    float* r_vertices = new float[vertSize];
    int count = 0;
    // Set up your rendering logic here
    // For example, bind the shader, set up the vertex data and draw
    for (const glm::vec3& vertex : renderComponent.vertices) {
        r_vertices[count] = vertex.x;
        r_vertices[count + 1] = vertex.y;
        r_vertices[count + 2] = vertex.z;
        r_vertices[count + 3] = renderComponent.color.r;
        r_vertices[count + 4] = renderComponent.color.g;
        r_vertices[count + 5] = renderComponent.color.b;
        r_vertices[count + 6] = renderComponent.color.a;
        count += noDimPerVertex;
    }

    const GLuint* r_indices = renderComponent.indices.data();

    VertexArray vao;
    VertexBuffer vbo(r_vertices, vertSize * sizeof(float));
    ElementBuffer ebo(r_indices, renderComponent.indices.size());

    vbo.Bind();

    VertexAttribute positionAttrib(0, 3, GL_FLOAT, GL_FALSE, noDimPerVertex * sizeof(float), (void*)0);
    VertexAttribute colorAttrib(1, 4, GL_FLOAT, GL_FALSE, noDimPerVertex * sizeof(float), (void*)(3 * sizeof(float)));

    GetShader().Use();
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
