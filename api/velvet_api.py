import httpx

async def call_velvex(input_str: str) -> str:
    async with httpx.AsyncClient() as client:
        try:
            response = await client.post(
                "https://velvex.onrender.com/process",
                json={"input": input_str}
            )
            response.raise_for_status()
            return response.text
        except httpx.RequestError as e:
            return f"Request failed: {str(e)}"
        except httpx.HTTPStatusError as e:
            return f"HTTP error occurred: {str(e)}"
